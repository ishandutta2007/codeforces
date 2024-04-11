#include<bits/stdc++.h>
using namespace std;

int T,n,p[200010],pp[200010];

int query(int a,int b,int c)
{
	printf("? %d %d %d\n",a,b,c),fflush(stdout);
	int ans; scanf("%d",&ans); return ans;
}

map<vector<int>,bool> Ma;

int main()
{
	mt19937 rng;
	scanf("%d",&T);
	while (T--)
	{
		Ma.clear();
		scanf("%d",&n);
		int lim=n/6-1,x,y;
		while (1)
		{
			int a=rng()%n+1,b=rng()%n+1,c=rng()%n+1;
			while (a==b) b=rng()%n+1;
			while (a==c||b==c) c=rng()%n+1;
			if (b>c) swap(b,c);
			if (a>b) swap(a,b);
			if (b>c) swap(b,c);
			vector<int> v={a,b,c};
			if (Ma[v]) continue;
			Ma[v]=1;
			if (query(a,b,c)<=lim) {x=a,y=b; break;}
		}
		for (int i=1; i<=n; i++) if (x!=i&&y!=i) pp[i]=query(i,x,y);
		int ma=0,maa1=0,maa2;
		for (int i=1; i<=n; i++)
			if (x!=i&&y!=i&&pp[i]>ma) ma=pp[i],maa1=i;
		vector<int> v; v.clear();
		for (int i=1; i<=n; i++)
			if (i!=x&&i!=y&&pp[i]==ma-1) v.push_back(i);
		if (v.size()==1) maa2=v[0];
		else assert(v.size()==2),maa2=(query(x,maa1,v[0])<query(x,maa1,v[1])?v[0]:v[1]);
		p[maa1]=1,p[maa2]=2;
		for (int i=1; i<=n; i++) if (i!=maa1&&i!=maa2) p[i]=query(i,maa1,maa2)+2;
		if (p[1]>p[2]) for (int i=1; i<=n; i++) p[i]=n-p[i]+1;
		printf("! "); for (int i=1; i<=n; i++) printf("%d ",p[i]);puts("");fflush(stdout);scanf("%d",&x);
	}
	return 0;
}

//99996