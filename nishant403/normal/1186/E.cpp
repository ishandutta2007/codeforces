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

int n,m,q,a,b,c,d;
int prefix[1001][1001];

int inv(int a,int b)
{
    int x = __builtin_popcountll(a)+__builtin_popcount(b);   
    return x&1;   
}

int getfull(int l,int r)
{
    int a1 = (l-1)/n,b1 = (r-1)/m;
    
    int res = (m*n*((a1*b1)/2));
    
    if(a1 % 2 == 1 && b1 % 2 == 1)
    {
       if(inv(a1-1,b1-1)==0) res+=prefix[n][m];    
       else res+=m*n-prefix[n][m];
    }
    
    return res;
}

int getcur(int l,int r)
{        
int aa = l%n;
if(l%n==0) aa = n;
    
int bb = r%m;
if(r%m==0) bb = m;
    
int x = prefix[aa][bb];    
    
int a1 = (l-1)/n;
int b1 = (r-1)/m; 
    
if(inv(a1,b1) == 0) return x;
return aa*bb - x;
}


int getleft(int l,int r)
{
int aa = l%n;
if(l%n==0) aa = n;
    
int bb = m;    
    
 int a1 = (l-1)/n;
 int b1 = (r-1)/m;  
    
 int res = (b1/2)*(aa*bb);
    
 int g = r - (r%m);
    
 if(r%m==0) g-=m;
     
 if(b1 % 2 == 1) res+=getcur(l,g);
    
 return res;   
}

int getup(int l,int r)
{
 int aa = n;
int bb = r%m;
if(r%m==0) bb = m;
    
int x = prefix[aa][bb];    

 int a1 = (l-1)/n;
 int b1 = (r-1)/m;
    
 int res = (a1/2)*(aa*bb);   
 
 int g = l-(l%n);
    
 if(l%n == 0) g-=n;
 if(a1 % 2 == 1) res+=getcur(g,r);   

 return res;
}

int query(int l,int r)
{
 if(l==0 || r==0) return 0;   
    
 return getfull(l,r)+getleft(l,r)+getup(l,r)+getcur(l,r);
}

void solve()
{
cin >> n >> m >> q;

string s;
    
f(i,n)
{
cin >> s;
f(j,m) prefix[i+1][j+1]=(s[j]=='1');
}
 
f(i,n)
    f(j,m)    
        prefix[i+1][j+1]+=prefix[i+1][j]+prefix[i][j+1]-prefix[i][j];
    
    
while(q--)
{
 cin >> a >> b >> c >> d;   
 cout << query(c,d) - query(a-1,d) - query(c,b-1) + query(a-1,b-1) << "\n";   
}
    
}

signed main()
{
    fast;
    solve();
}