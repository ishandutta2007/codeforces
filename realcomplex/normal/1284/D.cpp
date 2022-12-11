#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 9;

void NO(){
  cout << "NO\n";
  exit(0);
}

int n;
int l[N], r[N], p[N], q[N];
int cl[N], cr[N], cp[N], cq[N];
vector<pii> add[N], rem[N];

void solve(){
  for(int i = 0 ; i < N ; i ++ )
    add[i].clear(), rem[i].clear();
  vector<int> ss;
  for(int i = 0 ; i < n; i ++ ){
    cl[i] = l[i], cr[i] = r[i], cp[i] = p[i], cq[i] = q[i];
    cq[i] ++ ;
    ss.push_back(cp[i]);
    ss.push_back(cq[i]);
  }
  sort(ss.begin(), ss.end());
  ss.resize(unique(ss.begin(), ss.end()) - ss.begin());
  for(int i = 0 ; i < n; i ++ ){
    cp[i] = lower_bound(ss.begin(), ss.end(), cp[i]) - ss.begin();
    cq[i] = lower_bound(ss.begin(), ss.end(), cq[i]) - ss.begin();
    add[cp[i]].push_back(mp(l[i], r[i]));
    rem[cq[i]].push_back(mp(l[i], r[i]));
  }
  multiset<int> low, high;
  for(int i = 0 ; i < N ; i ++ ){
    for(auto x : rem[i]){
      low.erase(low.find(x.fi));
      high.erase(high.find(x.se));
    }
    for(auto x : add[i]){
      low.insert(x.fi);
      high.insert(x.se);
    }
    if(!low.empty()){
      auto i1 = low.end();
      --i1;
      auto i2 = high.begin();
      if(*i1 > *i2){
        NO();
      }
    }
  }
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> l[i] >> r[i] >> p[i] >> q[i];
  }
  solve();
  for(int i = 0 ; i < n; i ++ ){
    swap(l[i], p[i]);
    swap(r[i], q[i]);
  }
  solve();
  cout << "YES\n";
  return 0;
}