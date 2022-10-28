#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf =998244353;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll mul(ll x, ll y, ll mod) {
	ll ans = 0;
	while (y) {
		if (y&1) {
			ans += x;
			if (ans >= mod) ans -= mod;
		}
		x += x;
		if (x >= mod) x -= mod;
		y >>= 1;
	}
	return ans;
}

ll expo(ll x, ll y, ll mod) {
	ll ans = 1;
	while (y) {
		if (y&1) ans=(ans*1LL*x)%mod;
		x = (x*x)%mod;
		y>>=1;
	}
	return ans;
}


ll Expo(ll x, ll y, ll mod) {
	ll ans = 1;
	while (y) {
		if (y&1) ans=mul(ans,x,mod);
		x=mul(x,x,mod);
		y>>=1;
	}
	return ans;
}
bool isPrime(ll n) {
  if (n == 1) return false;
  vector<int> a={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; 
  if (find(all(a), n) != a.end()) return true;
  
  ll r=0,d=n-1;
  while(!(d&1))
    r++,d>>=1;  
  
  for(int i=0;i<a.size();i++)
  {
    long long x=Expo(a[i],d,n);
    if(x==1||x==n-1)  continue;
    for(int j=1;j<r;j++)
    {
      x=mul(x,x,n);
      if(x==1)  return false;
      if(x==n-1)  break;
    } 
    if(x==n-1)  continue;
    else  return false;
  }
  return true;
}



ll pw(ll n, int x) {
	ll en = 1414213570LL;
	if (x == 3) en = 1260000;
	if (x == 4) en = 37610;
	ll st = 1;
	const ll INF = 4e18;
	while (st < en) {
		ll mid= (st+en+1)/2;
		ll bc = expo(mid, x, INF);
		if (bc > n) en = mid - 1;
		else st = mid;
	}
	if (expo(st,x, INF) == n) return st;
	return 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	map<ll, int> mp;
	vector<ll> a(n);
	FOR (i, 0, n - 1) cin >> a[i];
	set<ll> st;

	FOR (j, 0, n - 1) {
		NFOR (i, 4, 2) {
			ll x = pw(a[j], i);
			if (x == 0) continue;
			mp[x] += i;
			a[j] = 1;
			st.insert(x);
			break;
		}
	}

	FOR (i, 0, n - 1) if (a[i]>1) {
		FOR (j, i+1, n-1) if (a[j]>1) {
			ll d = __gcd(a[i], a[j]);
			if (d != 1 and d < a[i] and d < a[j]) {
				st.insert(d); st.insert(a[i]/d), st.insert(a[j]/d);
			}
		}
	}
	set<ll> ST(all(st));
	FOR (i, 0, n - 1) {
		for (auto it : ST) if (a[i] % it == 0) st.insert(a[i]/it);
	}
	st.erase(1);
	FOR (i, 0, n - 1) if (a[i]>1) {
		for (auto it : st) {
			if (a[i] % it == 0) {
				mp[it]++, mp[a[i]/it]++;
				a[i]=1;
				break;
			}
		}
	}
	mp.erase(1);

	map<ll, int> MP;
	FOR (i, 0, n - 1) if (a[i] > 1) MP[a[i]]++;

	
	ll ans = 1;
	
	for (auto it : MP) {
		if (isPrime(it.F)) ans = (ans*(it.S+1))%inf;
		else ans = (ans*expo(it.S+1, 2, inf))%inf;
	}

	
	for (auto it :mp) {
		ans = (ans * (it.S+1))%inf;
	}
	cout << ans << endl;
	
	return 0;
}