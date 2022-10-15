#include <bits/stdc++.h>
using namespace std;
int star[100001];
struct seg
{
	int val[400001][60];
	int reset(int l, int r, int cur)
	{
		if (l==r)
		{
			for (int i=0;i<60;i++) if (i%star[l]==0) val[cur][i]=2; else val[cur][i]=1;
		}
		else
		{
			int mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
			for (int i=0;i<60;i++)
			{
				val[cur][i]=val[(cur<<1)][i]+val[(cur<<1)+1][(i+val[(cur<<1)][i])%60];
			}
		}
	}
	int update(int l, int r, int cur, int x)
	{
		if ((l<=x)and(x<=r))
		{
			
		if (l==r)
		{
			for (int i=0;i<60;i++) if (i%star[l]==0) val[cur][i]=2; else val[cur][i]=1;
		}
		else
		{
			int mid=(l+r)/2;
			update(l,mid,(cur<<1),x);
			update(mid+1,r,(cur<<1)+1,x);
			for (int i=0;i<60;i++)
			{
				val[cur][i]=val[(cur<<1)][i]+val[(cur<<1)+1][(i+val[(cur<<1)][i])%60];
			}
		}
		}
	}
	int get(int l, int r, int cur, int tl, int tr, int d)
	{
	//	cout<<"get "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<' '<<d<<endl;
		if ((tl>r)or(tr<l)) return 0;
		if ((tl<=l)and(tr>=r)) return val[cur][d];
		else
		{
			int mid=(l+r)/2;
			int aa=get(l,mid,(cur<<1),tl,tr,d);
			int bb=get(mid+1,r,(cur<<1)+1,tl,tr,(d+aa)%60);
			return aa+bb;
		}
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
	for (i=1;i<=m;i++)
	{
		char c;
		cin>>c;
		if (c=='C')
		{
			cin>>u>>v;
			star[u]=v;
			st.update(1,n,1,u);
		}
		else
		{
			cin>>u>>v;
			v--;
			cout<<st.get(1,n,1,u,v,0)<<endl;
		}
	}
}