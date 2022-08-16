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

const int MOD = 1e9+7;

const int N = 201;
const int K = 1003;

vector<vi> cur(N,vi(K,0)),nex(N,vi(K,0));

signed main()
{
    fast;
    
    int n,k;
    cin >> n >> k;
    
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0] = 0;
    sort(a,a+n+1);
   
    cur[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        f(j,n+1) f(v,k+1) nex[j][v] = 0;
        
        f(j,n+1) f(v,k+1)
        {
            int imbal = v + j*(a[i] - a[i-1]);
            
            if(imbal > k) continue;
            
            nex[j][imbal] += cur[j][v];
            nex[j][imbal] += j*cur[j][v];
            if(j < n) nex[j+1][imbal] += cur[j][v];
            if(j > 0) nex[j-1][imbal] += j*cur[j][v];
        }
        
        f(j,n+1) f(v,k+1) nex[j][v] %= MOD;
        
        swap(cur,nex);
    }
    
    int res = 0;
    f(i,k+1) res = (res + cur[0][i])%MOD;
    cout << res;
}