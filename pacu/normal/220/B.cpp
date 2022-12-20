#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100005
int T[MAXN+1];

void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}
void set(int i,int d)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] += d;
}
int getSum(int i)
{
	int c=0;
	for(i++;i>0;i-=(i&-i))
		c+=T[i];
	return c;
}

struct Query
{
	int l,r,ans,cid;
};

bool cmp(Query a,Query b)
{
	return a.r < b.r;
}
bool icmp(Query a,Query b)
{
	return a.cid < b.cid;
}

vector<int> loc[100001];
int occ[100001];
int lo[100001];
int hi[100001];
int A[100000];
Query B[100000];

int main()
{
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<Q;i++)
	{
		cin >> B[i].l >> B[i].r;
		B[i].l--,B[i].r--;
		B[i].cid = i;
	}
	sort(B,B+Q,cmp);
	init();
	for(int i=1;i<=N;i++)
		lo[i] = hi[i] = -1;
	int cur = 0;
	for(int i=0;i<Q;i++)
	{
		for(;cur<=B[i].r;cur++)
		{
			if(A[cur]>N)
				continue;
			loc[A[cur]].push_back(cur);
			occ[A[cur]]++;
			if(occ[A[cur]]<A[cur])
				continue;
			if(lo[A[cur]] != -1)
			{
				set(lo[A[cur]],-1);
				set(hi[A[cur]]+1,+1);
			}
			if(occ[A[cur]]==A[cur])
				lo[A[cur]] = 0;
			else
				lo[A[cur]] = loc[A[cur]][occ[A[cur]]-A[cur]-1]+1;
			hi[A[cur]] = loc[A[cur]][occ[A[cur]]-A[cur]];
			set(lo[A[cur]],+1);
			set(hi[A[cur]]+1,-1);
		}
		B[i].ans = getSum(B[i].l);
	}
	sort(B,B+Q,icmp);
	for(int i=0;i<Q;i++)
		cout << B[i].ans << "\n";
	return 0;
}