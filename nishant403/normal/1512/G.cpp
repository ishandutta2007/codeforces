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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 1e7 + 10;
int d[N];
int pre[N];

void pree()
{
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i) d[j] += i;
        
    for(int i=1;i<N;i++)
        if(d[i] < N && pre[d[i]] == 0) pre[d[i]] = i;
}
    

void solve()
{
   int n;
    cin >> n;
    
   if(pre[n] == 0) cout << -1 << '\n';
    else cout << pre[n] << '\n';
    
    
}

signed main()
{
    pree();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}