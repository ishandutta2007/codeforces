#include <bits/stdc++.h>
using namespace std;
typedef long long int_t; // Element type
typedef long long ll; // Element type
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004]; //Contains the current value of each node, as well as the lazy propagation amount stored.
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r) // Resets the tree nodes. 
    {
        if (l==r) 
        {
            lazy[node]=0;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=0;
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        int_t mid=(l+r)/2;
        val[node<<1]+=lazy[node]*(mid-l+1);
        val[(node<<1)+1]+=lazy[node]*(r-(mid+1)+1);
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]+=diff;
            val[node]+=diff*(r-l+1);
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return aa+bb;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r);
    }
};
ll n,m,i,j,k,t,u,v,a,b,buf;
ll arr[500011];
ll brr[500011];
ll prr[500011];
ll vtb[500011];
ll dp[500011];
map<ll,ll> dpval;
SegTree st;
int main()
{
	cin>>n;
	n++;
	for (i=1;i<n;i++) cin>>arr[i];
	arr[n]=n;
	for (i=1;i<n;i++)
	{
		cin>>prr[i];
		buf+=prr[i];
	}
	st.reset(n);
	cin>>m;
	m++;
	for (i=1;i<m;i++)
	{
		cin>>brr[i];
		vtb[brr[i]]=i;
	}
	brr[m]=n;
	vtb[n]=m;
	for (i=1;i<=n;i++) dpval[arr[i]]=-1e18;
	for (i=1;i<=m;i++)dpval[brr[i]]=-1e18;
	for (i=1;i<=n;i++)
	{
		if (prr[i]>0) st.update(arr[i],arr[i],prr[i]);
		else u=0;
		dp[i]=-1e18;
		if (vtb[arr[i]]==1) dp[i]=max(dp[i],ll(0));
		else if (vtb[arr[i]]>1)
		{
			u=st.get(1,brr[vtb[arr[i]]-1]);
			dp[i]=max(dp[i],dpval[brr[vtb[arr[i]]-1]]+u);
		}

		dp[i]+=prr[i];
	//	cout<<"i= "<<i<<" arr= "<<arr[i]<<" vtb= "<<vtb[arr[i]]<<" p= "<<prr[i]<<" u= "<<u<<" dp= "<<dp[i]<<endl;
		if (i<n)
		{
			v=st.get(1,brr[vtb[arr[i]]]);
	//		cout<<v<<endl;
			dpval[arr[i]]=max(dpval[arr[i]],dp[i]-v);
		}
	}
	if (dp[n]>=-1e16) cout<<"YES\n"<<buf-dp[n];
	else cout<<"NO";
}