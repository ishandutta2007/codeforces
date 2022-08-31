//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#include<bits/stdc++.h>
using namespace std;

#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll,ll>
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))

bool check(vector<ll> &b)
{
    ll n = b.size();
    for(ll i = 1; i < n  ;i++ )
        if(b[i] != b[0] ) return 0;
    return 1;
}
int main()
{
    FAST;
    ll n;
    cin >> n ;
    vector<ll > a(n) , b(n-1);
    for(ll i = 0 ;  i  < n ; i++ ) cin >> a[i];
    for(ll i = 1 ;  i  < n ; i++ ) b[i-1] = a[i] - a[i-1];
    if(check(b))
        cout << a[n-1] + b[n-2];
    else
        cout << a[n-1];
}