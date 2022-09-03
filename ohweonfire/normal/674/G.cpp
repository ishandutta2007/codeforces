#include <cstdio>
#include <random>
#include <utility>
#include <queue>

const int maxn=150111;
const int magic=800;

int n,m,p,a[maxn],tag[maxn];
void pushdown(int t)
{
	if(tag[t])
	{
		for(int i=t*magic;i<=n&&i<(t+1)*magic;i++)a[i]=tag[t];
		tag[t]=0;
	}
}
int query(int x)
{
	if(tag[x/magic])return tag[x/magic];
	return a[x];
}
void modify(int l,int r,int v)
{
	r++;
	if(l%magic)pushdown(l/magic);if(r%magic)pushdown((r-1)/magic);
	while(l<r&&l%magic)a[l++]=v;
	while(l<r&&r%magic)a[--r]=v;
	for(int i=l/magic;i<r/magic;i++)tag[i]=v;
}

int count[maxn],mark[maxn],seq[maxn],tot,timer;

std::mt19937 rng;
int rnd(int l,int r){return std::uniform_int_distribution<int>(l,r)(rng);}

void solve()
{
	timer++;
	for(int i=1;i<=tot;i++)
	{
		if(mark[seq[i]]!=timer)
		{
			mark[seq[i]]=timer;
			count[seq[i]]=0;
		}
		count[seq[i]]++;
	}
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > >pq;
	for(int i=1;i<=tot;i++)if(mark[seq[i]]==timer)
	{
		mark[seq[i]]=0;
		std::pair<int,int> v=std::make_pair(count[seq[i]],seq[i]);
		if(pq.size()<p||pq.top()<v)
		{
			if(pq.size()==p)pq.pop();
			pq.push(v);
		}
	}
	printf("%d",pq.size());
	while(!pq.empty())
	{
		printf(" %d",pq.top().second);
		pq.pop();
	}
	puts("");
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);p=100/p;
	
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	
	for(int i=1;i<=m;i++)
	{
		int tp,l,r,v;
		scanf("%d%d%d",&tp,&l,&r);
		if(tp==1)
		{
			scanf("%d",&v);
			modify(l,r,v);
		}
		else
		{
			tot=0;
			if(r-l+1<=magic)
			{
				for(int j=l;j<=r;j++)
					seq[++tot]=query(j);
			}
			else
			{
				for(int j=1;j<=magic;j++)
					seq[++tot]=query(rnd(l,r));
			}
			solve();
		}
	}
	
	return 0;
}