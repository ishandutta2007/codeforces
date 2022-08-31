 
//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#pragma optimize("", off)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:36777216")
#include<bits/stdc++.h>
using namespace std;

#define MINF LONG_LONG_MIN
#define pi acos(-1)
#define bp __builtin_popcount
#define ll long long int
#define ld long double
#define pii pair<ll , ll>
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Fori(i,a,b,p) for(ll i=a;i<b;i+=p)
#define Ror(i,a,b) for(ll i=a;i>b;i--)
#define Rori(i,a,b,p) for(ll i=a;i>b;i-=p)

#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 

#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))



int main()
{
    ll n ;
    cin >> n;
    vector<ll> ip(n) , a(n) , b(n) ;
    ll ans = -1;
    For(i,0,n)  cin >> ip[i];
    a[0] = 1;
    For(i,1,n)  a[i] = min( a[i-1] + 1 , ip[i] );
    b[n-1] = 1;
    Ror(i,n-2,-1)  b[i] = min( b[i+1] + 1 , ip[i] );
    For(i,0,n) a[i] = min(a[i] , b[i]) , ans = max(ans , a[i]);
    cout << ans;
}