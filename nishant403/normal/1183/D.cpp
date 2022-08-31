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

int check(int n)
{
    
    int d = (n%10);
    d+=(n/10)%10;
    d+=(n/100)%10;
    d+=(n/1000)%10;
    
    return d;
}

void solve()
{
int n,x;
cin >> n;
    
map<int,int> m;
    
f(i,n)
{
    cin >> x;
    m[x]++;
}
    
priority_queue<int> P;
 
for(auto z : m) P.push(z.S);
    
int prev = 2*n;
int sum = 0;  
    
while(!P.empty())
{
 int h = P.top();
 P.pop();
    
 if(h<prev)
 {
  prev = h;
  sum+=h;   
 }
 else
 {
  if(prev>0) prev--;
  sum+=prev;   
 }
    
}
    
    cout << sum << "\n";
}

signed main()
{
    fast;int t=1;
    cin >> t;
    while(t--)
    solve();
}