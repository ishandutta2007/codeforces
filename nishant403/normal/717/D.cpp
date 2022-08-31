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

const int N = 128;

vector<double> poly(N,0);
vector<double> temp(N,0);

vector<double> merge(vector<double> & a,vector<double> & b)
{
    vector<double> res(N,0);
    
    f(i,N) f(j,N) res[i^j]+=(a[i]*b[j]);
    
    return res;
}

void solve()
{
    int n,x;
    cin >> n >> x;
    
    temp[0] = 1.00000;
    
    f(i,x+1) cin >> temp[i];
    
    poly[0] =1;
   
    while(n)
    {
       if(n&1) poly = merge(poly,temp);
       temp = merge(temp,temp);
       n>>=1;
    }
    
    cout << fixed<< setprecision(7) << 1-poly[0];
}

signed main()
{
    fast;
    solve();
}