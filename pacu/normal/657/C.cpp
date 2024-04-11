#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int t[400000];
long long k[400000],nw[400000];
int cid[200000];
long long B,C;
long long N,K;

struct cmp
{
	bool operator()(int a,int b)
	{
		if(k[a]-B*nw[a] == k[b]-B*nw[b])
			return a<b;
		return (k[a]-B*nw[a] < k[b]-B*nw[b]);
	}
};

set<int,cmp> S;
set<int,cmp>::iterator it;
long long sm;

void update(long long v)
{
	if((k[v]-B*nw[v] < k[*it]-B*nw[*it]))
	{
		sm += k[v]-B*nw[v];
		sm -= k[*it]-B*nw[*it];
		S.insert(v);
		it--;
		//cout << sm << '\n';
//		cout << k[v]-B*nw[v] << '\n';
	}
}

bool scmp(int a,int b)
{
	return nw[a]<nw[b];
}

int mod(int a)
{
	if(a>=0) return a%5;
	return (5 - ((-a)%5))%5;
}

int main()
{
	cin >> N >> K >> B >> C;
	for(int i=0;i<N;i++)
	{
		cin >> t[i];
	//	t[i] = -1000000000;
	}
	for(int i=200000;i<200000+K;i++)
		k[i] = 2000000000000LL, nw[i] = 0;
	B = min(B,5*C);
	long long ans = 1000000000000000000LL;
	for(int m=0;m<5;m++)	//-----------
	{
		S.clear();
		for(int i=0;i<K;i++)
			S.insert(200000+i);
		it = S.end();
		it--;
		sm = K*2000000000000LL;
		for(int i=0;i<N;i++)
		{
			int c = t[i];
			k[i] = 0;
			while(mod(c) != m)
				c++, k[i]+=C;
			nw[i] = (c-m)/5;
			cid[i] = i;
		}
		sort(cid,cid+N,scmp);
		for(int i=0;i<N;i++)
		{
//			cout << k[cid[i]] << ' ' << nw[cid[i]] << '\n';
		//	cout << k[cid[i]]-B*nw[cid[i]] << '\n';
			update(cid[i]);
			if(i>=K-1)
				ans = min(ans,K*B*nw[cid[i]]+sm);
		}
	}
	cout << ans << '\n';
}