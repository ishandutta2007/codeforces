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

const int inf = 1e15;

int dis(pii x,pii y)
{
    if(x.S < y.F) return y.F - x.S;
    
    else if(y.S < x.F) return x.F - y.S;
        
    return 0;
}

void solve()
{
   pii a[4];
    f(i,4) cin >> a[i].F >> a[i].S;
    
   vector<int> go(4);
    f(i,4) go[i] = i;
  
   int res = inf; 
   
    do
    {
        pii b[4];
        f(i,4) b[i] = a[go[i]];
        
        int temp = 0;
        
        temp+=abs(b[0].F - b[1].F);
        temp+=abs(b[2].F - b[3].F);
        temp+=abs(b[0].S - b[2].S);
        temp+=abs(b[1].S - b[3].S);
        
        pii rx1 = {min(b[0].F,b[1].F),max(b[0].F,b[1].F)};
        pii rx2 = {min(b[2].F,b[3].F),max(b[2].F,b[3].F)};
        
        int x1 = rx1.F - rx2.S;
        int x2 = rx1.S - rx2.F;
        pii xx;
        
        if(x1 >= 0) xx = {x1,x2};
        else if(x1 < 0 && x2 >= 0) xx = {0,max(abs(x1),abs(x2))};
        else xx = {abs(x2),abs(x1)};
        
        pii ry1 = {min(b[0].S,b[2].S),max(b[0].S,b[2].S)};
        pii ry2 = {min(b[1].S,b[3].S),max(b[1].S,b[3].S)};
      
        int y1 = ry1.F - ry2.S;
        int y2 = ry1.S - ry2.F;
        pii yy;
        
        if(y1 >= 0) yy = {y1,y2};
        else if(y1 < 0 && y2 >= 0) yy = {0,max(abs(y1),abs(y2))};
        else yy = {abs(y2),abs(y1)};
        
        temp+=2*dis(xx,yy);
        
        res = min(res,temp);
        
    }while(next_permutation(go.begin(),go.end()));
    
   cout << res << '\n';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}