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

const int N = 2e4 + 50;
const int inf = 1e18;

vector<int> cur(N),nex(N);
vector<int> cur2(N),nex2(N);

int x[N];
int y[N];
int n,m,p;

inline int fun(int a,int b)
{
    return (x[a] + y[b]) >= p ? (x[a] + y[b] - p) : x[a] + y[b];
}

int solve(int a,int b,int c,int d)
{
   for(int j=b;j<=d;j++) cur[j] = nex[j] = 0;
    
   for(int i=a;i<=c;i++)
   {
       for(int j=b;j<=d;j++)
       {
           nex[j] = max(nex[j],fun(n-i,m-j) + cur[j]);
           
           if(j > b) 
               nex[j] = max(nex[j], fun(n-i,m-j) + nex[j-1]);
       }
       
       swap(cur,nex);
   }
    
   return cur[d]; 
}

int solve_rev(int a,int b,int c,int d)
{
   for(int i=b;i<=d;i++) cur2[i] = nex2[i] = 0;
    
   for(int i=c;i>=a;i--)
   {
       for(int j=d;j>=b;j--)
       {
           nex2[j] = max(nex2[j],fun(n-i,m-j) + cur2[j]);
           
           if(j < d) 
               nex2[j] = max(nex2[j], fun(n-i,m-j) + nex2[j+1]);
       }
       
       swap(cur2,nex2);
   }
    
   return cur2[b]; 
}

int temp1[N],temp2[N];

int call = 0;

void get_path(int a,int b,int c,int d)
{
    if(a == c)
    {
        while(b < d) 
        {
            cout << 'S';
            b++;
        }
        
        return;
    }
    
    int mid = (a + c)/2;
    
    solve(a,b,mid,d);
    solve_rev(mid+1,b,c,d);
    
    int id = b;
    
    for(int j=b;j<=d;j++)
        if(cur[j] + cur2[j] >= cur[id] + cur2[id]) id = j;

    get_path(mid+1,id,c,d); 
  
    cout << 'C';
  
    get_path(a,b,mid,id); 
}

void solve()
{
   cin >> n >> m >> p;
   
   f(i,n) cin >> x[i];
   f(i,m) cin >> y[i];
   f(i,n) x[i] %= p;
   f(i,m) y[i] %= p;
    
   cout << solve(1,1,n,m) << '\n'; 
   get_path(1,1,n,m);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}