#include <bits/stdc++.h>
using namespace std;
struct seg
{
	int val[1200001],lazy[1200001];
	int n;
	void resetK(int l, int r, int cur)
	{
		lazy[cur]=0;
		val[cur]=0;
		if (l<r)
		{
			int mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
		}
	}
	void reset(int nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(int cur)
	{
		val[(cur<<1)]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
		lazy[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		lazy[cur]=0;
	}
	void updateK(int l, int r, int cur, int tl, int tr, int diff)
	{
//		cout<<"update "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<' '<<diff<<endl;
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r))
		{
			val[cur]+=diff;
			lazy[cur]+=diff;
		}
		else
		{
			flusha(cur);
			int mid=(l+r)/2;
			updateK(l,mid,(cur<<1),tl,tr,diff);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,diff);
			val[cur]=min(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void update(int l, int r, int diff)
	{
		updateK(1,n,1,l,r,diff);
	}
	int getK(int l, int r, int cur, int tl, int tr)
	{
//		cout<<"get "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<endl;
		if ((tl>r)or(tr<l)) return 1e9;
		if ((tl<=l)and(tr>=r))
		{
			return val[cur];
		}
		else
		{
			flusha(cur);
			int mid=(l+r)/2;
			int aa=getK(l,mid,(cur<<1),tl,tr);
			int bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return min(aa,bb);
		}
	}
	int get(int l, int r)
	{
		return getK(1,n,1,l,r);
	}
	int bsK(int l, int r, int cur, int tar)
	{
//		cout<<"bs "<<l<<' '<<r<<' '<<cur<<' '<<tar<<endl;
		if (l==r)
		{
			if (val[cur]>=tar) return l+1;
			else return l;
		}
		else
		{
			flusha(cur);
			int mid=(l+r)/2;
			if (val[(cur<<1)]<tar) return bsK(l,mid,(cur<<1),tar);
			else return bsK(mid+1,r,(cur<<1)+1,tar);
		}
	}
	int bs(int tar)
	{
		return bsK(1,n,1,tar);
	}
};
seg st;
int arr[1000001],l[300001],r[300001];
vector<int> buc[300001];
int res[300001];
int n,m,i,j,k,t,u,v,a,b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for (i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i];
		l[i]++;
		r[i]=n-r[i];
	//	cout<<l[i]<<' '<<r[i]<<endl;
		buc[r[i]].push_back(i);
	}
	st.reset(n);
	for (i=1;i<=n;i++)
	{
	//	cout<<i<<endl;
		if (arr[i]<=i)
		{
			u=st.bs(-arr[i]+i);
	//		cout<<u<<' ';
			if (u>1) st.update(1,min(u-1,i),1);
		}
	//	cout<<endl;
		for (int g : buc[i])
		{
			res[g]=st.get(l[g],l[g]);
		}
	}
	for (i=1;i<=m;i++) cout<<res[i]<<endl;
}