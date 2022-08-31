#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 506;
int n,m,q;
int a[4][N][N];
string s;

int b[N][N];

bool go(int l1,int r1,int l2,int r2,int c)
{
    int sum = a[c][l2][r2];
    if(l1>0) sum-=a[c][l1-1][r2];
    if(r1>0) sum-=a[c][l2][r1-1];
    if(l1>0 && r1>0) sum+=a[c][l1-1][r1-1];
    
    int tot = (r2-r1+1)*(l2-l1+1);
    return (sum == tot);
}

bool is(int i,int j,int k)
{
    int flag = 1;
    i-=(k-1);
    j-=(k-1);
    flag&=go(i,j,i+k-1,j+k-1,0);
    flag&=go(i,j+k,i+k-1,j+k+k-1,1);
    flag&=go(i+k,j,i+k+k-1,j+k-1,3);
    flag&=go(i+k,j+k,i+k+k-1,j+k+k-1,2);
    
    return flag;
}

int seg[2*N][2*N];

void ux(int x,int y,int val)
{
    int yy = y;
    
    for(x+=n;x>1;x>>=1)
    {
        y = yy + m;
        
        if(x<n) seg[x][y] = max(seg[x<<1][y],seg[x<<1^1][y]); 
        else seg[x][y] = val;
        
        for(;y>1;y>>=1) seg[x][y>>1] = max(seg[x][y],seg[x][y^1]);
    }
}

int qy(int x,int y1,int y2)
{
    int res = 0;
    
    for(y1+=m,y2+=m+1;y1<y2;y1>>=1,y2>>=1)
    {
        if(y1&1) res=max(res,seg[x][y1++]);
        if(y2&1) res=max(res,seg[x][--y2]);
    }
    
    return res;
}
 
int qx(int x1,int y1,int x2,int y2)
{   
    int res = 0;
    
    for(x1+=n,x2+=n+1;x1<x2;x1>>=1,x2>>=1)
    {
        if(x1&1) res=max(res,qy(x1++,y1,y2));
        if(x2&1) res=max(res,qy(--x2,y1,y2));
    }
    
    return res;
}

void prepare()
{
    
  f(k,4) 
  {
    f(i,n-1) a[k][i+1][0]+=a[k][i][0];
    f(j,m-1) a[k][0][j+1]+=a[k][0][j];   
     
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
           a[k][i][j]+=a[k][i-1][j]+a[k][i][j-1]-a[k][i-1][j-1];
  }
    
  f(i,n) f(j,m)
  {
     int lim = min(j+1,i+1);
     lim = min(lim,n-i-1);
     lim = min(lim,m-j-1);
      
     int l = 0;
     int r = lim;
      
     while(l<=r)
     {
         int mid = (l+r)/2;
         if(is(i,j,mid))
         {
             b[i][j]= max(b[i][j],mid);
             l = mid + 1;
         }
         else r = mid - 1;
     }
  }
    
  f(i,n) f(j,m) ux(i,j,b[i][j]);    
}

bool foo(int l1,int r1,int l2,int r2,int k)
{
    return (qx(l1+k-1,r1+k-1,l2-k,r2-k) >= k);
}

void solve()
{
   cin >> n >> m >> q;
    
   f(i,n)
   {
       cin >> s;
       f(j,m)
       {
           if(s[j] == 'R') a[0][i][j] = 1;
           if(s[j] == 'G') a[1][i][j] = 1;
           if(s[j] == 'B') a[2][i][j] = 1;
           if(s[j] == 'Y') a[3][i][j] = 1;
       }
   }
     
   prepare();
 
   int l1,r1,l2,r2;
 
   while(q--)
   {
       cin >> l1 >> r1 >> l2 >> r2;
       l1--; r1--; l2--; r2--;
       
       int l = 1;
       int r = min(r2-r1+1,l2-l1+1)/2;
       int ans = 0;
       
       while(l<=r)
       {
           int mid = (l+r)/2;
           
           if(foo(l1,r1,l2,r2,mid))
           {
               ans=max(ans,mid);
               l = mid + 1;
           }
           else r = mid - 1;
       }
       
       ans*=2;
       ans*=ans;
       
       cout << ans << '\n';
   }
    
}

signed main()
{
    fast;
    solve();
}