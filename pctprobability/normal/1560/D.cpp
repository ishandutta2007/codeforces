#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define int long long
#define ll long long
#define REP(i, n) for (long long i = 0; i < (int)(n); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ld = long double;
using pll = pair<ll, ll>;
using Graph = vector<vector<ll>>;
using in = int;
struct Edge
{
  int to;
  int w;
  Edge(int to, int w) : to(to), w(w) {}
};
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const string YYY = "YES";
const string yyy = "Yes";
const string NNN = "NO";
const string nnn = "No";
template <class T>
void chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
  }
}
template <class T>
void chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
  }
}
template <class T>
void rm(vector<T> &vec) { vec.erase(unique(vec.begin(), vec.end()), vec.end()); }

ll GD(ll num)
{ //
  ll digit = 0;
  while (num != 0)
  {
    digit += num % 10;
    num /= 10;
  }
  return digit;
}
bool if_integer(ld x)
{ //
  return std::floor(x) == x;
}
const ll MMM = 998244353;

vector<ll> fac(300001);  //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,b

ll mpow(ll x, ll n)
{ //x^n(mod M) pow(x,n)mod
  ll ans = 1;
  while (n != 0)
  {
    if (n & 1)
      ans = ans * x % MMM;
    x = x * x % MMM;
    n = n >> 1;
  }
  return ans;
}
ll comb(ll a, ll b)
{ //aCbmod
  if (a == 0 && b == 0)
    return 1;
  if (a < b || a < 0)
    return 0;
  ll tmp = ifac[a - b] * ifac[b] % MMM;
  return tmp * fac[a] % MMM;
}
bool if_prime(ll x)
{
  bool a = true;
  for (ll i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      a = false;
      break;
    }
  }
  if (x == 1)
    a = false;
  return a;
}
ll gcd(ll x, ll y) //
{
  if (x % y == 0)
  {
    return (y);
  }
  else
  {
    return (gcd(y, x % y));
  }
}

ll lcm(ll x, ll y) //
{
  return x / gcd(x, y) * y;
}
inline ll mod(ll a, ll m)
{
  return (a % m + m) % m;
}
ll modPow(ll a, ll n, ll p)
{
  if (n == 0)
    return 1; // 0
  if (n == 1)
    return a % p;
  if (n % 2 == 1)
    return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}
ll my_upper_bound(vector<ll> &v, ll find, ll N)
{
  ll right, left;
  ll res = -1; // 
  left = 0;
  right = N - 1;
  while (left <= right)
  {
    ll middle = (left + right) / 2;

    if (find < v[middle])
    {
      // v[middle]  find . ()
      res = middle;
      right = middle - 1;
    }
    else
    {
      // v[middle]  find .
      left = middle + 1;
    }
  }
  return res;
}
ll BinarySearch(vector<ll> &v, ll find)
{
  // key: 
  ll right, left;
  left = 0;
  right = v.size();

  while (left < right)
  {
    ll mid = (left + right) / 2;
    if (v[mid] == find)
    {
      return mid;
    }
    else if (find < v[mid])
    {
      // 
      right = mid;
    }
    else if (v[mid] < find)
    {
      // 
      // 
      left = mid + 1;
    }
  }
  // key 
  return -1;
}
template <typename T>
vector<T> compress(vector<T> &X)
{
  vector<T> vals = X;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < (int)X.size(); i++)
  {
    X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
  }
  return vals;
}
/*
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d < 1; d++) {  // ()
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // 
    sort(vals.begin(), vals.end());
    // (unique), (erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}*/
/////////////////////////
/////////////////////////
/////////////////////////
signed main()
{
  /*fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % MMM; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, MMM-2) % MMM; // k!^{M-2} (mod M) mpow
    }
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(),vec.end());
  vector<vector<long long>> dp(N+1, vector<long long>(W+1,0));
*/
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << std::fixed << std::setprecision(50);
  ////////////////////////////
  ///////////////////////////
  in t;cin>>t;
  in sum=1;
  vector<string>vec(60);
  string S=to_string(sum);
  vec[0]=S;
  for(int i=1;i<=59;i++){
    sum*=2;
    //if(sum>=MOD)cout<<i<<endl;
    string s=to_string(sum);
    vec[i]=s;
  }
  rep(i,t){
    string k;cin>>k;
    int ans=100;
    rep(i,60){
      string n=vec[i];
      int now=0;
      for(int i=0;i<k.size();i++){
        if(k[i]==n[now]) now++;
        if(now==n.size()) break;
      }
      int ans2=n.size()+k.size()-2*now;
      chmin(ans,ans2);
    }
    cout<<ans<<endl;
  }
}