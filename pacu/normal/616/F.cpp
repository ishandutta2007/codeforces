#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string s;
int tid[1000000],dist[1000000],c[1000000];
int L,dif;
int sa[1<<21],pos[1<<21],tmp[1<<21],lcp[1<<21];

bool scmp(int i,int j)
{
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i+=dif,j+=dif;
	if(i<L && j<L) return pos[i]<pos[j];
	else return i>j;
}

void build()
{
	//cout << s << '\n';
	//cout << L << '\n';
	for(int i=0;i<L;i++)
		sa[i] = i, pos[i] = s[i];
	for(dif=1;;dif*=2)
	{	
		sort(sa,sa+L,scmp);
		for(int i=0;i<L-1;i++)
			tmp[i+1] = tmp[i]+scmp(sa[i],sa[i+1]);
		for(int i=0;i<L;i++)
			pos[sa[i]] = tmp[i];
		if(tmp[L-1]==L-1)
			break;
	}
	for(int i=0,k=0;i<L;i++)
	{
		if(pos[i]!=L-1)
		{
			for(int j=sa[pos[i]+1];s[i+k]==s[j+k];)
				k++;
			lcp[pos[i]] = k;
			if(k) k--;
		}
	}
}

string t[100000];

int fid[1000000],sz[1000000];
long long sm[1000000];

void init()
{
	for(int i=0;i<L;i++)
	{
		fid[i] = i, sz[i] = 1, sm[i] = c[sa[i]];
	}
}
int find(int i)
{
	if(fid[i]==i) return i;
	fid[i] = find(fid[i]);
	return fid[i];
}
void join(int i,int j)
{
	i = find(i), j =find(j);
	if(i==j) return;
	if(sz[i]>sz[j]) swap(i,j);
	fid[i] = j;
	sz[j] += sz[i];
	sm[j] += sm[i];
}

int cid[1000000];
bool cmp(int a,int b)
{
	return lcp[a]<lcp[b];
}

int cost[100000];

int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> t[i];
		for(int j=s.size();j<s.size()+t[i].size();j++)
		{
			tid[j] = i;
			dist[j] = s.size()+t[i].size()-j;
		}
		s += t[i];
		if(i<N-1) s += '#';
	}
	L = s.size();
	build();
	for(int i=0;i<L;i++)
		lcp[i] = min(lcp[i],dist[sa[i]]);
//	for(int i=0;i<L;i++)
//		cout << lcp[i] << ' ';
	//cout << '\n';
	for(int i=0;i<N;i++)
		cin >> cost[i];
	for(int i=0;i<L;i++)
		c[i] = cost[tid[i]];
	for(int i=0;i<L-1;i++)
		cid[i] = i;
	sort(cid,cid+L-1,cmp);
	init();
	long long ans = 0;
	for(int i=0;i<L;i++)
		if((i==0 || dist[sa[i]]>lcp[i-1])&&(i==L-1 || dist[sa[i]]>lcp[i]))
			ans = max(ans,dist[sa[i]]*((long long)c[sa[i]]));
	vector<int> upd;
	for(int i=L-2;i>=0;i--)
	{
		join(cid[i],cid[i]+1);
		//cout << "Joining " << cid[i] << " with " << cid[i]+1 << '\n';
		upd.push_back(cid[i]);
		if(i==0 || lcp[cid[i]] != lcp[cid[i-1]])
		{
			for(int j=0;j<upd.size();j++)
				ans = max(ans,lcp[cid[i]]*sm[find(upd[j])]);
			upd.clear();
		}
	}
	cout << ans << '\n';
}