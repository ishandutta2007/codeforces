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

vi primes;
const int N = 75;
const int BT = 19;
int num[N];
int inv[N];

void pre()
{
    for(int i=2;i<N;i++)
    {
        int flag = 1;
        
        for(int j=2;j<i;j++) if(i%j==0) flag = 0;
          
        if(flag == 1) primes.pb(i);
    }
    
    for(int i=1;i<=70;i++)
    {
        int temp = i;
        bitset<BT> nu = 0;
        
        for(int j=0;j<primes.size();j++)
        {
            while((temp%primes[j]) == 0)
            {
               nu[j] = (1 - nu[j]);
               temp/=primes[j];
            }
        }
        
        num[i] = nu.to_ullong();
    }
}

vi cur(1LL<<BT,0),nexT(1LL<<BT,0);

void solve()
{
    int n;
    cin >> n;
    
    int x;
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
    {
        cin >> x;
        mp[num[x]]++;
    }
    
    
    cur[0] = 1;
    
    for(auto x : mp)
    {
        nexT = cur;
        int ways = mod_pow(2,x.S-1);
        
        f(i,1LL<<BT) 
        {
            nexT[i] = ((cur[i] + cur[i^x.F])*ways)%MOD;
        }
            
        swap(nexT,cur);
    }
    
    cout << cur[0]-1;
}

signed main()
{
    pre();
    
    fast;
        
    solve();
}