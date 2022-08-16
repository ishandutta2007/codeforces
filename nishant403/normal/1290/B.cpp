#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;
const int N = 2e5+10;
int seg[2*N];
int n;

void upd(int id,int val)
{
    int mask = (1LL<<val);
    id+=n;
    
    for(seg[id] = mask;id>1;id>>=1)
        seg[id>>1] = seg[id] | seg[id^1];
}

int query(int l,int r)
{
    int res = 0;
    
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1)
    {
        if(l&1) res|=seg[l++];
        if(r&1) res|=seg[--r];
    }
    
    return res;
}

int cnt(int x)
{
    int res = 0;
    
    while(x) 
    {
        if(x&1) res++;
        x>>=1;
    }
    
    return res;
}

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
    string s;
    cin >> s;
    
    n = s.length();
    
    f(i,n) upd(i,s[i]-'a');
    
    int q;
    cin >> q;
    
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--; r--;
        
        if(s[l] != s[r])
        {
            cout <<"Yes\n";
            continue;
        }
        
        if(r-l+1 == 1)
        {
            cout <<"Yes\n";
            continue;
        }
        
        //3 distinct chars
        if(cnt(query(l,r)) > 2)
        {
            cout <<"Yes\n";
            continue;
        }
        
        cout <<"No\n";
    }
}

signed main()
{
    fast;
    solve();
}