#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e7 + 10;
const int NN = 1e6 + 10;

pii ids[N];
int id[N][2];
int a[NN];

void solve()
{
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) 
    {
        cin >> a[i];
        
        if(id[a[i]][0] == 0) id[a[i]][0] = i;
        else id[a[i]][1] = i;
    }
    
    long long res = 1e18;
    pii ans = {-1,-1};
    
    a[0] = 1e9;
    
    for(int i=N-1;i>=1;i--)
    {
        int t[2];
        t[0] = id[i][0];
        t[1] = id[i][1];
        
        for(int j=i+i;j<N;j+=i)
        {
            if(t[1] > 0) break;
            
            if(id[j][0] != 0)
            {
                if(t[0] == 0) t[0] = id[j][0];
                else t[1] = id[j][0];
            }
        }
        
        if(t[1] == 0) continue;
        
        long long temp_res = (1LL*a[t[0]]*a[t[1]])/(i);
        
        if(temp_res < res)
        {
            res = temp_res;
            ans = {t[0],t[1]};
        }
    }
    
    if(ans.F > ans.S) swap(ans.F,ans.S);
    
    cout << ans.F << ' ' << ans.S;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}