#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif


using namespace std;

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

ll seg[maxn];
ll arr[maxn];
ll brr[maxn];
int q;

void build(int idx, int l, int r)
{
	if(l==r)
	{
		seg[idx] = 0;
		return;
	}

	int m = l+r;
	m/=2;

	build(idx+idx,l,m);
	build(idx+idx+1,m+1,r);
	seg[idx] = 0;
}

void update(int idx, int l, int r, int ql, int qr)
{	
	if (qr < l || r < ql) return;

	if(ql<=l && qr>=r)
	{
		//cout<<idx<<" "<<l<<" --> "<<r<<" = "<<q<<endl;
		seg[idx] = q;
		return;
	}

	int m = l+r;
	m/=2;

	update(idx+idx,l,m,ql,qr);
	update(idx+idx+1,m+1,r,ql,qr);
}

int query(int idx, int l , int r, int v)
{
	int ans = seg[idx];

	if(l>v || r < v)
		return 0;
	if(l==r)
	{
		//cout<<idx<<" "<<l<<" -> "<<r<<" --- "<<seg[idx]<<endl;
		return seg[idx];
	}

	int m = l+r;
	m/=2;

	ans = max(ans,query(idx+idx,l,m,v));
	ans = max(ans,query(idx+idx+1,m+1,r,v));

	//out<<idx<<" "<<l<<" -> "<<r<<" --- "<<ans<<endl;
	return ans;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    	cin>>arr[i];

    for(int i=1;i<=n;i++)
    	cin>>brr[i];

    vector<int> x;
    x.pb(0);
    q = 1;
    int t,l,r,k;
    for (int i = 0; i < m; ++i)
    {
    	cin>>t;

    	if(t==2)
    	{
    		cin>>k;
    		l = query(1,1,n,k);
    		//cout<<l<<" ----- ";
    		if(l==0)
    		{
    			cout<<brr[k]<<endl;
    		}
    		else
    			cout<<arr[k+x[l]]<<endl;
    	}
    	else
    	{
    		cin>>l>>r>>k;
    		//cout<<r<<" -> "<<r+k-1<<endl;
    		update(1,1,n,r,r+k-1);
    		q++;
    		x.pb(l-r);
    	}
    }
	    
}