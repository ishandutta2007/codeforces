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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

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
int n;
int mini;
int arr[maxn];
int ans[maxn];
int t[maxn];

int query(int l, int r) {  // sum on interval [l, r)
  int res = inf;
  for (l += n+n+n, r += n+n+n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(t[l++],res);
    if (r&1) res = min(t[--r],res);
  }
  return res;
}

int findMaxAns(int idx)
{
	//cout<<"-----"<<idx<<endl;
	int val = arr[idx];
	val = (val+1)/2;
	
	//cout<<"val:"<<val<<endl;
	if(val<=mini)
		return inf;
	
	int l = 1;
	int r = n-1;
	int mid;
	int x;
	while(l<r)
	{
		mid = l+r;
		mid/=2;
		//cout<<"l,r: "<<l<<" "<<r<<endl;
		x = query(idx+l,idx+mid+1);
		//cout<<"mid,x "<<mid<<" "<<x<<endl;
		if(x<val)
		{
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	
	return l;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    cin>>n;
    mini = inf;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	mini = min(arr[i],mini);
    	arr[n+i]=arr[i];
    	arr[n+n+i] = arr[i];
    	
    	t[n+n+n+i] = arr[i];
    	t[n+n+n+n+i] = arr[i];
    	t[n+n+n+n+n+i] = arr[i];
    }
    
    for (int i = n+n+n - 1; i > 0; --i) 
    {
    	t[i] = min(t[i<<1],t[i<<1|1]);
    }
    
    int idx = 0;
    int maxi = arr[0];
    
    for(int i=0;i<n;i++)
    {
    	if(arr[i]>maxi)
    	{
    		maxi = arr[i];
    		idx = i;
    	}
    }
    
    ans[idx] = findMaxAns(idx);
    
    if(ans[idx]==inf)
    {
    	for(int i=0;i<n;i++)
    		cout<<"-1 ";
    	cout<<endl;
    	return 0;
    }
    
    
    int j = idx;
    int i  = (idx-1+n)%n;
    while(i!=idx)
    {
    	//cout<<i<< " "<<j<<endl;
    	if(arr[j]>=arr[i])
    	{
    		ans[i] = ans[j]+1;
    		//cout<<i<<endl;
    	}
    	else
    	{
    		//cout<<i<<" "<<findMaxAns(i)<<endl;
    		ans[i] = min(ans[j]+1,findMaxAns(i));
    	}
    	
    	j = i;
    	i  = (i-1+n)%n;
    }
    
    for(int i=0;i<n;i++)
    	cout<<ans[i]<<" ";
    cout<<endl;
    
}