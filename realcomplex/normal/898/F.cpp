#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e6 + 1234;
ll mod[2] = {424146869,1219473721};
ll inv[N][2];
ll suffix[N][2];
ll cur[2];

ll addition(ll a,ll b,ll x){
  return (a + b) % x;
}

ll removal(ll a,ll b,ll x){
  return (a - b + x ) % x;
}

ll multi(ll a,ll b, ll x){
  return (a * b) % x;
}

int sz;

ll bin_pow(ll n, ll k, ll md){
  if(k == 0LL)
    return 1LL;
  ll x = bin_pow(n,k/2,md);
  x = multi(x,x,md);
  if(k & 1)
    x = multi(x,n,md);
  return x;
}

void ic(){
  for(int i = 0;i<2;i++)
    cur[i] = multi(cur[i], 10LL, mod[i]);
}

string s;

bool correct(int s1, int s2, int s3){
  if(s3 <= 0 or s1 <= 0 or s2 <= 0)
    return false;
  if(s[0] == '0' and s1 > 1)
    return false;
  if(s[s1] == '0' and s2 > 1)
    return false;
  if(s[s1 + s2] == '0' and s3 > 1)
    return false;
  ll v3[5];
  ll v2[5];
  ll v1[5];
  for(int j = 0;j<2;j++){
    v3[j] = suffix[s1 + s2][j];
  }
  for(int j = 0;j<2;j++){
    v2[j] = removal(suffix[s1][j],suffix[s1 + s2][j], mod[j]);
    v2[j] = multi(v2[j],inv[s3][j], mod[j]);
  }
  for(int j = 0;j<2;j++){
    v1[j] = removal(suffix[0][j],suffix[s1][j], mod[j]);
    v1[j] = multi(v1[j],inv[s2 + s3][j],mod[j]);
  }
  for(int j = 0;j<2;j++){
    if(addition(v1[j],v2[j],mod[j]) != v3[j])
      return false;
  }
  return true;
}

void Output(int s1, int s2, int s3){
  for(int i = 0;i<s1;i++){
    cout << s[i];
  }
  cout << "+";
  for(int j = s1;j<s1+s2;j++){
    cout << s[j];
  }
  cout << "=";
  for(int j = s1+s2;j<s1+s2+s3;j++){
    cout << s[j];
  }
  exit(0);
}

int main(){
  fastIO;
  cin >> s;
  sz = len(s);
  for(int j = 0;j<2;j++)
    cur[j] = 1;
  ll k;
  for(int i = sz-1;i>=0;i--){
    k = s[i] - 48;
    for(int j = 0;j < 2;j++){
      suffix[i][j] = multi(k , cur[j], mod[j]);
      suffix[i][j] = addition(suffix[i][j],suffix[i+1][j],mod[j]);
    }
    ic();
  }
  for(int j = 0;j<2;j++)
    cur[j] = 1;
  for(int j = 0;j <= sz;j++){
    for(int x= 0 ;x< 2;x++){
      inv[j][x] = bin_pow(cur[x],mod[x] - 2,mod[x]);
    }
    ic();
  }
  for(int s3 = 0;s3 <= sz/2;s3++){
    if(s3 <= 0)
      continue;
    if(s3 * 3 < sz)
      continue;
    if(correct(s3,sz-(s3 + s3),s3))Output(s3,sz-(s3 + s3),s3);
    if(correct(s3-1,sz-(s3 + (s3 - 1)),s3))Output(s3-1,sz-(s3 + (s3 - 1)),s3);
    if(correct(sz-(s3 + (s3 - 1)),s3-1,s3))Output(sz-(s3 + (s3 - 1)),s3-1,s3);
    if(correct(sz-(s3 + s3),s3,s3))Output(sz-(s3 + s3),s3,s3);
  }
  return 0;
}