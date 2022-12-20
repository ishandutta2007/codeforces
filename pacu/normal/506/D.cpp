#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
using namespace std;

class UnionFind
{
private:
	unordered_map<int,int> id;
	unordered_map<int,int> sz;
public:
	inline int find(int i)
	{
		int j = id[i];
		while(id[j] != j) j = id[j];
		id[i] = j;
		return j;
	}
	inline void join(int a,int b)
	{
		if(sz.count(a)==0) {id[a]=a;sz[a] = 1;}
		if(sz.count(b)==0) {id[b]=b;sz[b] = 1;}
		int ra = find(a);
		int rb = find(b);
		if(ra == rb) return;
		if(sz[ra] <= sz[rb])
		{
			id[ra] = rb;
			sz[rb] += sz[ra];
		}
		else
		{
			id[rb] = ra;
			sz[ra] += sz[rb];
		}
	}
};

class ColorList
{
public:
	unordered_set<int> S;
	vector<int> v;
	inline void insert(int c)
	{
		if(S.count(c)>0)
			return;
		S.insert(c);
		v.push_back(c);
	}
	inline bool contains(int c)
	{
		return (S.count(c)>0);
	}
};

unordered_map<long long,int> memo;
UnionFind U[100000];
ColorList L[100000];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	int c;
	long long a,b;
	for(int i=0;i<M;i++)
	{
		scanf("%I64d %I64d %d",&a,&b,&c);
		a--,b--,c--;
		U[c].join(a,b);
		L[a].insert(c);
		L[b].insert(c);
	}
	int Q;
	int ans;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%I64d %I64d",&a,&b);
		a--,b--;
		if(a>b)
			swap(a,b);
		if(L[a].v.size() > L[b].v.size())
			swap(a,b);
		ans = 0;
		if(memo.count(100000LL*a+b)==0)
		{
			for(int i=0;i<L[a].v.size();i++)
			{
				if(L[b].contains(L[a].v[i]))
					ans += (U[L[a].v[i]].find(a)==U[L[a].v[i]].find(b));
			}
			memo[100000LL*a+b] = ans;
		}
		else
			ans = memo[100000LL*a+b];
		printf("%d\n",ans);
	}
}