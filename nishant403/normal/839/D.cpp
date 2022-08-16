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
#define all(x) x.begin(),x.end()

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e6 + 10;

vector<int> phi(N);

void sieve_phi()
{
    for(int i=0;i<N;i++) phi[i] = i;
    
    for(int i=2;i<N;i++)
    {
      if(phi[i] == i)
          for(int j=i;j<N;j+=i)
             phi[j] -= (phi[j]/i);
    }
}

int fre[N];
int ways[N];

signed main()
{
    sieve_phi();

    fast;
    
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    f(i,n) fre[a[i]]++;
    
    for(int i=1;i<N;i++)
        for(int j=i+i;j<N;j+=i) fre[i] += fre[j];
    
    int res = 0;
    
    for(int i=N-1;i>=2;i--)
    {
        ways[i] = mod_pow(2 , fre[i]  - 1);
        ways[i] *= fre[i];
        ways[i] %= MOD;
        
        for(int j=i+i;j<N;j+=i)
        {
            ways[i] -= ways[j];
            if(ways[i] < 0) ways[i] += MOD;
        }
        
        res += i*ways[i];
        res %= MOD;
    }
    
    cout << res;
}