#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

const int N = 2e5+1;

int data[N][5]={0};
int n;
int dp[N][10];    

int solve(int nn,int kk)
{
    if(nn == -1 )
    {
        if(kk == 0) return 0; 
        else return -9999999999999999;       
    }
    
    if(dp[nn][kk] != -1 ) return dp[nn][kk];
    
    int ans = -9999999999999999;    
  
    ans = max ( ans, solve(nn-1,kk) );
    
    int choice = data[nn][4];
    
    if(choice > 0 )
    {
        if(kk == 0) choice*=2;
        ans = max(ans,choice  + solve(nn-1,(kk+9)%10) );   
    }
    
    choice = data[nn][3];
    
    if(choice > 0)
    {
        if(kk == 0) choice*=2;
        ans = max(ans,choice  + solve(nn-1,(kk+9)%10) );       
    }
    
    choice = data[nn][0];
    
    if(choice > 0)
    {
        if(kk == 0) choice*=2;
        ans = max(ans,choice  + solve(nn-1,(kk+9)%10) );       
    }
    
    choice = data[nn][0]+data[nn][1];
    
    if(data[nn][1] > 0 && data[nn][0] > 0)
    {
        if(kk == 0 || kk == 1) choice+=data[nn][0];
        
        ans = max(ans,choice  + solve(nn-1,(kk+8)%10) );       
    }
    
    choice = data[nn][0]+data[nn][1]+data[nn][2];
    
    if(data[nn][1] > 0 && data[nn][0] > 0 && data[nn][2] > 0)
    {
        if(kk==0 || kk==1 || kk==2) choice+=data[nn][0];
        ans = max(ans,choice  + solve(nn-1,(kk+7)%10) );       
    }
    
    choice = data[nn][0]+data[nn][3];
    
    if(data[nn][3] > 0 && data[nn][0] > 0)
    {
        if(kk==0 || kk==1) choice+=max(data[nn][0],data[nn][3]);
        ans = max(ans,choice  + solve(nn-1,(kk+8)%10) );       
    }
 
return dp[nn][kk] = ans;    
}

signed main()
{
cin >> n;  
    
memset(dp,-1,sizeof(dp));
 
for(int i=0;i<n;i++)   
{
 int k,a,b;
    
 cin >> k;   
  
 int m4,m5;
 vector<int> aa;   
    
 m4=m5=-999999999999999;   
    
 f(j,k) 
 {
  cin >> a >> b;  
     
 if(a==3) m5 = max(m5,b); 
 else if(a==2) m4 = max(m4,b);    
 else aa.pb(b);    
 }   
    
  aa.pb(-99999999999999999);
  aa.pb(-99999999999999999);
  aa.pb(-99999999999999999);  
   
 sort(aa.rbegin(),aa.rend());   
 
data[i][0] = aa[0];
data[i][1] = aa[1];
data[i][2] = aa[2];
data[i][3] = m4;
data[i][4] = m5;
    
}
    
    int ans = -9999999999999999;
    
    for(int i=0;i<10;i++) ans = max ( ans, solve(n-1,i) );
    
    cout << ans;
}