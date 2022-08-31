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

const int N = 105;

int cur[N][N*N];
int nex[N][N*N];

void solve()
{
   int n;
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    
   double tot = 0.0000000000;
   f(i,n) tot += a[i].S;
   
   for(int i=0;i<=n;i++)
     for(int j=0;j<=(n*100);j++)
       cur[i][j] = nex[i][j] = -1e9;
    
   cur[0][0] = 0;   
   nex[0][0] = 0; 
    
   f(i,n)  
   {
       for(int j=1;j<=n;j++)
           for(int k=a[i].S;k<=(j*100);k++)
                   nex[j][k] = max(nex[j][k] , cur[j-1][k-a[i].S] + a[i].F);
           
       for(int j=0;j<=n;j++)
           for(int k=0;k<=(j*100);k++)
               cur[j][k] = nex[j][k];
   }
    
   for(int i=1;i<=n;i++)
   {
       int ans = 0;
       
       for(int j=0;j<=i*100;j++)
       {
           int chosen_sum = j;
           int not_chosen_sum = (tot - chosen_sum);
           int chosen_capacity = cur[i][j];
           
           int temp_ans = 2*chosen_sum + min(2*(chosen_capacity - chosen_sum),not_chosen_sum);
           
           ans = max(ans,temp_ans);
       }
       
       cout << precise(9) << (double)ans/2.00000 << ' ';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}