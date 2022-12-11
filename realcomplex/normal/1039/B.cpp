#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue


mt19937 rnd(time(0));

bool ask(ll l, ll r){
  cout << l << " " << r << endl;
  string ans;
  cin >> ans;
  if(ans == "Bad")
    exit(0);
  bool ret = ans == "Yes";
  if(l == r){
    if(ret) {
      exit(0);
    }
  }
  return ret;
}

int main(){
  ll n;
  int k;
  cin >> n >> k;
  ll l = 1, r = n;
  ll md;
  ll len;
  ll rd;
  for(int x = 0; x < 4500; x ++ ){
    len = (r - l + 1);
    if(len > 4 * k + 3){
      md = (l + r)/2;
      if(ask(l, md) == true)
        r = md;
      else
        l = md + 1;
    }
    else{
      rd = rnd() % len;
      if(ask(l + rd, l + rd))   
        exit(0);
    }
    l = max(l - k, 1ll);
    r = min(r + k, n);
  }
  return 0;
}