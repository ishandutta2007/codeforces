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

const int N = (int)150000 + 999;
ll ans[N];
set<pii> dat;

void process(){
  auto x = dat.upper_bound(mp(0,0));
  ll vl = x -> fi;
  int ix = x -> se;
  auto y = dat.upper_bound(mp(vl,ix));
  ll v = y -> fi;
  int i = y -> se;
  if(v != vl){
    ans[ix] = vl;
    dat.erase(dat.begin());
    return;
  }
  v += vl;
  dat.erase(dat.begin());
  dat.erase(dat.begin());
  dat.insert(mp(v,i));
}

void last(){
  if(dat.empty())
    return;
  auto x = dat.begin();
  ans[x -> se] = x -> fi;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  for(int i =1;i <= n;i ++){
    cin >> x;
    dat.insert(mp(x,i));
  }
  while(dat.size() >= 2){
    process();
  }
  last();
  vector<ll>rez;
  for(int i = 1;i <= n;i ++ ){
    if(ans[i] != 0)
      rez.push_back(ans[i]);
  }
  cout << rez.size() << "\n";
  for(auto x : rez)
    cout << x << " ";
  cout << "\n";
  return 0;
}