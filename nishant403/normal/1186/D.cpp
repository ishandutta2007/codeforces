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

const double EPS = 1e-9;

void solve()
{
int n;
cin >> n;
    
double a[n],b[n];
    
f(i,n) cin >> a[i];
    
double resi = 0;
   
f(i,n) b[i]=ceil(a[i]);   
f(i,n) resi+=(b[i] - a[i]);    
    
int x = round(resi);    
    
assert(x >= 0);    
    
f(i,n)
{
 if(x==0) break;
    
 if(fabs(a[i]-b[i]) < EPS) continue;   
 x--;
 b[i]--;   
    
}

f(i,n) if(abs(b[i]) < EPS) b[i] = abs(b[i]);    
    

f(i,n) cout << b[i] << "\n";    
    
}

signed main()
{
    fast;
    solve();
}