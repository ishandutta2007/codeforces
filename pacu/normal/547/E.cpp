#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int N;

int lc[500000];
int sa[500000];
int tmp[500000],pos[500000];
int dif;

bool scmp(int a,int b)
{
	if(pos[a] != pos[b])
		return pos[a]<pos[b];
	a += dif, b += dif;
	if(a<N && b<N)
		return pos[a]<pos[b];
	return a>b;
}

void suffix()
{
	for(int i=0;i<N;i++)
		sa[i] = i, pos[i] = s[i];
	for(dif=1;tmp[N-1]<N-1;dif<<=1)
	{
		sort(sa,sa+N,scmp);
		for(int i=1;i<N;i++)
			tmp[i] = tmp[i-1]+scmp(sa[i-1],sa[i]);
		for(int i=0;i<N;i++)
			pos[sa[i]] = tmp[i];
	}
}

#define MOD 1000000007
#define B 37
long long pw[500000],hpref[500000];
void initHash()
{
	pw[0] = 1;
	for(int i=1;i<500000;i++)
		pw[i] = (((long long)pw[i-1])*B)%MOD;
	hpref[0] = (s[0]+1-'[');
	for(int i=1;i<N;i++)
		hpref[i] = (((long long)hpref[i-1])*B+(s[i]+1-'['))%MOD;
}
int ghash(int i,int j)
{
	if(i==0) return hpref[j];
	return (hpref[j]+MOD-(hpref[i-1]*pw[j+1-i])%MOD)%MOD;
}

int fEq[200000],lEq[200000];

int bsLast(int low,int high,int len,int h)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(ghash(sa[high],sa[high]+len) == h) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(ghash(sa[mid],sa[mid]+len) == h) return bsLast(mid,high,len,h);
	return bsLast(low,mid-1,len,h);
}
int bsFirst(int low,int high,int len,int h)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(ghash(sa[low],sa[low]+len) == h) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(ghash(sa[mid],sa[mid]+len) == h) return bsFirst(low,mid,len,h);
	return bsFirst(mid+1,high,len,h);
}

int sStart[200000],sEnd[200000];

int qAns[500000];

int qloc[1000000],qval1[1000000],qval2[1000000];
int sortid[1000000];

bool cmp(int a,int b)
{
	return qloc[a]<qloc[b];
}

#define MAXN 500500
int T[MAXN+1];

int getSum(int i)
{
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}
void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	string t;
	int nS,Q;
	cin >> nS >> Q;
	for(int i=0;i<nS;i++)
	{
		cin >> t;
		sStart[i] = s.size();
		s += t;
		sEnd[i] = s.size()-1;
		if(i<(nS-1))
			s += '[';
	}
	N = s.size();
	suffix();
	initHash();
	for(int i=0;i<nS;i++)
	{
		fEq[i] = bsFirst(0,pos[sStart[i]],sEnd[i]-sStart[i],ghash(sStart[i],sEnd[i]));
		lEq[i] = bsLast(pos[sStart[i]],N-1,sEnd[i]-sStart[i],ghash(sStart[i],sEnd[i]));
	}
	int a,b,c;
	for(int i=0;i<Q;i++)
	{
		cin >> a >> b >> c;
		a--,b--,c--;
		sortid[2*i] = 2*i, sortid[2*i+1] = 2*i+1;
		qloc[2*i] = fEq[c]-1, qloc[2*i+1] = lEq[c];
		qval1[2*i] = qval1[2*i+1] = sStart[a];
		qval2[2*i] = qval2[2*i+1] = sEnd[b];
	}
	sort(sortid,sortid+2*Q,cmp);
	init();
	int j = 0;
	int cur;
	for(int i=0;i<2*Q;i++)
	{
		cur = sortid[i];
		while(j <= qloc[cur])
		{
			set(sa[j],1);
			j++;
		}
		if(cur&1)
			qAns[cur>>1] += getSum(qval2[cur]) - ((qval1[cur]>0)?getSum(qval1[cur]-1):0);
		else
			qAns[cur>>1] -= getSum(qval2[cur]) - ((qval1[cur]>0)?getSum(qval1[cur]-1):0);
	}
	for(int i=0;i<Q;i++)
		cout << qAns[i] << '\n';
	return 0;
}