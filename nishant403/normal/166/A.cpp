#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int M = 1e9+7;
const int N = 2*(1e5);

bool comp(const pii & a,const pii & b)
{
 if(a.F == b.F) return a.S < b.S;
 return a.F > b.F;
}

signed main()
{
Fast;    
    
int n,k;
    cin >> n >> k;
    
    vector<pii> a(n);
    
    f(i,n) cin >> a[i].F >> a[i].S;
    
    sort(a.begin(),a.end(),comp);
    
    int c = 0;
    
    f(i,n) if(a[i].F==a[k-1].F && a[i].S==a[k-1].S) c++;
        cout << c;
 
}