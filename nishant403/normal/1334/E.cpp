#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int MOD = 998244353;
const int N = 102;

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

vector<int> fact(N),ifact(N);

void pre()
{
    //Factorial and Inverse Factorial
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%MOD;
        
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--) ifact[i] = (ifact[i+1]*(i+1))%MOD;
}


void solve()
{
    int n;
    cin >> n;
    
    set<int> st;
    
    for(int i=2;(i*i)<=n;i++)
    while(n%i==0)
    {
        n/=i;
        st.insert(i);
    }
    
    if(n > 1) st.insert(n);
    
    vi go;
    for(auto x : st) go.pb(x);
    
    int q;
    cin >> q;
    
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        
        int res1 = 1;
        int tot1 = 0;
        int res2 = 1;
        int tot2 = 0;
        
        for(auto x : go)
        {
            int pa = 0;
            int pb = 0;
            
            while(u%x == 0)
            {
                u/=x;
                pa++;
            }
            
            while(v%x == 0)
            {
                v/=x;
                pb++;
            }
            
            if(pa == pb) continue;
            else if(pa < pb)
            {
            tot1+=pb-pa;
            res1 = (res1*ifact[pb-pa])%MOD;
            }
            else
            {
            tot2+=pa-pb;
            res2 = (res2*ifact[pa-pb])%MOD;
            }
            
        }
        
        res1 = (res1*fact[tot1])%MOD;
        res2 = (res2*fact[tot2])%MOD;
        res1=(res1*res2)%MOD;
        
        cout << res1 << '\n';
        
    }
}


signed main()
{
    pre();
    fast;
    solve();
}