#include <bits/stdc++.h>
using namespace std;
int star[200001];
struct seg
{
	int val[800001],lazy[800001][101];
	int reset(int l, int r, int cur)
	{
		for (int i=1;i<=100;i++) lazy[cur][i]=i;
		if (l==r)
		{
			val[cur]=star[l];
		}
		else
		{
			int mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
		}
	}
	void flusha(int cur)
	{
		for (int i=1;i<=100;i++)
		{
			lazy[(cur<<1)][i]=lazy[cur][lazy[(cur<<1)][i]];
			lazy[(cur<<1)+1][i]=lazy[cur][lazy[(cur<<1)+1][i]];
		}
		val[(cur<<1)]=lazy[cur][val[(cur<<1)]];
		val[(cur<<1)+1]=lazy[cur][val[(cur<<1)+1]];
		for (int i=1;i<=100;i++) lazy[cur][i]=i;
	}
	void update(int l, int r, int cur, int tl, int tr, int x, int y)
	{
//		cout<<"update "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<' '<<x<<' '<<y<<endl;
		if ((tl>r)or(tr<l)) return;
		else if ((tl<=l)and(tr>=r))
		{
			for (int i=1;i<=100;i++) if (lazy[cur][i]==x) lazy[cur][i]=y;
			if (val[cur]==x) val[cur]=y;
		}
		else
		{
			flusha(cur);
			int mid=(l+r)/2;
			update(l,mid,(cur<<1),tl,tr,x,y);
			update(mid+1,r,(cur<<1)+1,tl,tr,x,y);
		}
	}
	int get (int l, int r, int cur, int x)
	{
//		cout<<"get "<<l<<' '<<r<<' '<<cur<<' '<<x<<endl;
		if ((l<=x)and(x<=r))
		{
			if (l==r) return val[cur];
			else 
			{
				flusha(cur);
				int mid=(l+r)/2;
				int aa=get(l,mid,(cur<<1),x);
				int bb=get(mid+1,r,(cur<<1)+1,x);
				return max(aa,bb);
			}
		}
		else return 0;
	}
};
seg st;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++) cin>>star[i];
	st.reset(1,n,1);
	cin>>m;
//	for (j=1;j<=n;j++) cout<<st.get(1,n,1,j)<<' '; cout<<endl;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a>>b;
		st.update(1,n,1,u,v,a,b);
//	for (j=1;j<=n;j++) cout<<st.get(1,n,1,j)<<' '; cout<<endl;
	}
	for (i=1;i<=n;i++) cout<<st.get(1,n,1,i)<<' ';
}