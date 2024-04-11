/*
		Max segtree with binary search capabilities.
		This allows you to find the first/last element in a range
		greater than a given value.
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//

typedef long long int_t; // Element type
int_t star[1000001];
struct seg
{
	int val[4000401],lazy[4000401];
	vector<piii(int)> nodes;
	int n;
	void resetK(int l, int r, int cur)
	{
		if (l==r)
		{
			lazy[cur]=0;
			val[cur]=star[l];
		}
		else
		{
			lazy[cur]=0;
			int mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void reset(int nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(int cur)
	{
	//	cout<<"flusha "<<cur<<endl;
	//	cout<<"before: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[(cur<<1)]+=lazy[cur];
		val[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
	//	cout<<"after: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[cur]=0;
	}
	void updateK(int l, int r, int cur, int tl, int tr, int d)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r)) 
		{
	//		cout<<"update directly "<<cur<<' '<<d<<endl;
	//		cout<<"before: "<<val[cur]<<' '<<lazy[cur]<<endl;
			val[cur]+=d;
			lazy[cur]+=d;
	//		cout<<"after: "<<val[cur]<<' '<<lazy[cur]<<endl;
		}
		else
		{
			int mid=(l+r)/2;
			flusha(cur);
			updateK(l,mid,(cur<<1),tl,tr,d);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,d);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void update(int l, int r, int d)
	{
        	//cout<<"upd "<<l<<' '<<r<<' '<<d<<endl; 
		if (l>r) return;
		updateK(1,n,1,l,r,d);
	//	debug();
	}
	void debugK(int l, int r, int cur)
	{
		cout<<"---------------------------------\n";
		cout<<"Now crawling node: "<<cur<<endl;
		cout<<"Covering range: ("<<l<<","<<r<<")"<<endl;
		cout<<"It's values: "<<"val = "<<val[cur]<<" lazy = "<<lazy[cur]<<endl;
		cout<<"---------------------------------\n";
		int mid=(l+r)/2;
		if (l<r)
		{
		debugK(l,mid,(cur<<1));
		debugK(mid+1,r,(cur<<1)+1);
		}
	}
	void debug()
	{
		debugK(1,n,1);
	}
	int getK(int l, int r, int cur, int tl, int tr)
	{
		if ((tl>r)or(tr<l)) return -1;
		if ((tl<=l)and(tr>=r)) 
		{
			return val[cur];
		}
		else
		{
			int mid=(l+r)/2;
			flusha(cur);
			int aa=getK(l,mid,(cur<<1),tl,tr);
			int bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return max(aa,bb);
		}
	}
	int get(int l, int r)
	{
		if (l>r) return -1;
		return getK(1,n,1,l,r);
	}
	void get_nodes(int l, int r, int cur, int tl, int tr)
	{
		if ((tl>r)or(tr<l)) return ;
		if ((tl<=l)and(tr>=r)) 
		{
			nodes.push_back({cur,{l,r}});
		}
		else
		{
			int mid=(l+r)/2;
            flusha(cur);
			get_nodes(l,mid,(cur<<1),tl,tr);
			get_nodes(mid+1,r,(cur<<1)+1,tl,tr);
		}
	}
	int bsK(int l, int r, int cur, int x)
	{
		if (l==r)
		{
			if (val[cur]<=x) return l+1;
			else return l;
		}
		else
		{
			int mid=(l+r)/2;
			flusha(cur);
			if (val[(cur<<1)]>x) return bsK(l,mid,(cur<<1),x);
			else return bsK(mid+1,r,(cur<<1)+1,x);
		}
	}
	
	int bs(int l, int r, int x)
	{
	//	cout<<"bs "<<l<<' '<<r<<' '<<x<<endl;
		nodes.clear();
		get_nodes(1,n,1,l,r);
	//	cout<<"nodes:\n";
		for (int i=0;i<nodes.size();i++)
		{
		//	cout<<nodes[i].fi<<' '<<nodes[i].se.fi<<' '<<nodes[i].se.se<<endl;
			if (val[nodes[i].fi]>x) 
            {
            auto u=bsK(nodes[i].se.fi,nodes[i].se.se,nodes[i].fi,x);
			return u;
            }
		}
		return r+1;
	}
};
seg st;






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
    	if (l>r) return;
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
    	if (l>r) return 0;
        return getK(1,1,tree_n,l,r);
    }
};
SegTree sta;








int n,m,i,j,k,t,t1,u,v,a,b;
int l[300001],r[300001],arr[300001];
vector<pii(int)> cha[300001];
struct cmp
{
    int operator()(piii(int) a, piii(int) b) const
    {
        return (a.p2<b.p2);
    }
};
set<piii(int),cmp> sett;
void prep()
{
    ll res=0;
    vector<piii(ll)> toa;
    sett.clear();
    sett.insert({0,{1e9,n+1}});
    for (int i=n;i>=1;i--)
    {
        auto it=sett.lower_bound({l[i],{l[i],0}});
        toa.clear();
        while(true)
        {
        //cout<<"upd "<<it->p3<<' '<<n<<' '<<-(it->p2)+(it->p1)<<endl;
            if (it->p1<l[i]) toa.push_back({it->p1,{l[i],it->p3}});
            if (it->p2>r[i]) toa.push_back({r[i],{it->p2,it->p3}});
            if (it->p3<=n+1) cha[i].push_back({it->p3,-(it->p2)+(it->p1)});
            if (it->p2>=r[i])
            {
                sett.erase(it);
                break;
            } 
            it=sett.erase(it);
        }
       // cout<<"pre "<<i<<' '<<l[i]<<' '<<r[i]<<endl;
        toa.push_back({l[i],{r[i],i}});
        for (auto g: toa)
        {
            //cout<<"upd2 "<<g.p3<<' '<<n<<' '<<g.p2-g.p1<<endl;
            if (g.p3<=n+1) cha[i].push_back({g.p3,g.p2-g.p1});
            sett.insert(g);
        }
    }
}
ll sum(int x)
{
    ll res=0;
    ll j=n;
    ll i;
    ll cnt=0;
    sta.reset(n);
    for (i=1;i<=n;i++) arr[i]=0;
    for (i=n;i>=1;i--)
    {
        for (auto g : cha[i]) 
        {
            arr[g.fi]+=g.se;
            sta.update(g.fi,n,g.se);
            if ((i<=g.fi)and(g.fi<=j)) cnt+=g.se;
        }
        while ((j>=i)and(cnt-arr[j]>=x))
        {
            cnt-=arr[j];
            j--;
        }
        if (cnt>=x) res+=sta.get(j,n);
    }
    return res;
}
ll count(int x)
{
    ll res=0;
    ll j=n;
    ll i;
    ll cnt=0;
    for (i=1;i<=n;i++) arr[i]=0;
    for (i=n;i>=1;i--)
    {
        for (auto g : cha[i]) 
        {
            arr[g.fi]+=g.se;
            if ((i<=g.fi)and(g.fi<=j)) cnt+=g.se;
        }
        while ((j>=i)and(cnt-arr[j]>=x))
        {
            cnt-=arr[j];
            j--;
        }
        if (cnt>=x) res+=n-j+1;
    }
    return res;
}
ll res=0;
int main()
{
    fio;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>l[i]>>r[i];
    int lp=0,rp=1e9;
    int mid;
prep();
    while(lp<rp)
    {
        int mid=(lp+rp)/2;
	//    cout<<lp<<' '<<rp<<endl;
        if (count(mid)<=k) rp=mid; else lp=mid+1;
    }
	//cout<<lp<<endl;
    res+=(k-count(lp))*(lp-1);
    res+=sum(lp);
    cout<<res;
}