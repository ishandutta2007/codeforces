// NOT MY CODE
// https://codeforces.com/contest/235/submission/81692496

// Problem : A. LCM Challenge
// Contest : Codeforces - Codeforces Round #146 (Div. 1)
// URL : https://codeforces.com/problemset/problem/235/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
#include<bits/stdc++.h>
 
#define pb push_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define hell1 1000000007
#define hell2 1000000009
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long long
#define ld long double 
#define no_of_digits(n) floor(log10(n)) + 1
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define see(x) cout << #x << "=" << x << endl;
#define see2(x, y) cout << #x << "=" << x << "\t" << #y << "=" << y << endl;
#define see3(x, y, z) cout << #x << "=" << x << "\t" << #y << "=" << y << "\t" << #z << "=" << z << endl;
#define INF 1e9+5
#define LL_MAX 1e18+5
 
using namespace std;
 
const ld PI = acos((ld)-1);
 
ll modmult(ll a,ll b, ll p=hell1){   return ((a%p)*(b%p))%p; }
ll modmultbig(ll a,ll b,ll mod=hell1){   if(a==0 or b==0) return 0;if(a==1 or b==1) return (a*b)%mod;ll cur=modmultbig(a,b/2,mod);cur=(2*cur)%mod;if(b%2) cur=(cur+a)%mod;return cur;}
ll modadd(ll a, ll b, ll p=hell1){ if(a>=p) a%=p; if(b>=p) b%=p; if(a+b>p) return (a + b)%p; else return a+b;}
ll modsub(ll a, ll b, ll p=hell1){return (a%p - b%p + p)%p;}
ll fpow(ll n, ll k, ll p = hell1) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = modmult(r,n,p); n = modmult(n,n,p);} return r;}
ll inv(ll a, ll p = hell1) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = hell1){ll m0 = m;ll y = 0, x = 1;if (m == 1)return 0;while (a > 1){ll q = a / m;ll t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}
 
int isPowerof2(ll x) { return (x && !(x & (x-1))); } 
 
ll log2(ll x) { ll res = 0; while (x >>= 1) res++; return res; } 
 
bool isPerfectSquare(long double x) {long double sr = sqrt(x); return ((sr - floor(sr)) == 0); }
 
bool boundary(ll i,ll j,ll n, ll m){return (i>=0 && i<n && j>=0 &&  j<m);} //matrix boundary checking
 
ll ceil(const ll &a, const ll &b){return (a - 1)/b + 1;}
ll lcm(ll a, ll b){return a/__gcd(a, b)*b;}
 
string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
 
// cout << fixed for removing e notation
 
bool comp2(const pair<int, int>&a, const pair<int, int>&b)
{
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
    {
        if(a.fi > b.fi) return true;
        else return false;
    }
    else return false;
}
 
bool prime[10000005];
void SieveOfEratosthenes(int n) 
{
    memset(prime, true, sizeof(prime)); 
    prime[0] = prime[1] = 0;
    for (int p=2; p*p<=n; p++) 
    {
        if (prime[p] == true) 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
    }
}
 
int main()
{
	ios
	ll n;
	cin >> n;
	
	if(n%2)
	{
		if(n == 1) cout << 1 << "\n";
		else cout << n*(n-1)*(n-2);
		
		return 0;
	}
	else
	{
		if(n == 2) cout << 2 << "\n";
		else
		{
			ll ans = -1;
			for(ll i=max((ll)1, n-50);i<=n;i++)
			{
				for(ll j=max((ll)1, n-50);j<=n;j++)
				{
					for(ll k=max((ll)1, n-50);k<=n;k++)
					{
						ll temp = lcm(i, j);
						ll lc = lcm(temp, k);
						
						ans = max(ans, lc);						
					}
				}
			}
			
			cout << ans << "\n";
		}
		return 0;
	}
}