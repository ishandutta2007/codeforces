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

void solve()
{
int k,temp = 1,ans = 0;
 
cin >> k;    
    
string s; 

cin >> s;
    
int n = s.length();    
    
vector<int> d1(n,0),d2(n,0);    
    
    
if(k==0)
{
    int temp = 0;
    
    f(i,n)
    {
     if(s[i]=='1')temp=0; 
     else temp++;
        
     ans+=temp;   
    }
    
    cout << ans;
   
    return;
}
    
    
f(i,n)
{
    if(s[i] == '1') {d1[i] = temp; temp = 1;}
    else temp++; 
}
  
temp = 1;    
    
for(int i=n-1;i>=0;i--)   
{
    if(s[i] == '1') {d2[i] = temp; temp = 1;}
    else temp++; 
}
    
vi id;
    
f(i,n) if(s[i]=='1') id.pb(i);    
    
if(id.size() < k) { cout << 0; return; }    
    
f(i,id.size()-k+1) ans +=d1[id[i]]*d2[id[i+k-1]];    
   
cout << ans;    
    
}

signed main()
{
    fast;
    solve();
}