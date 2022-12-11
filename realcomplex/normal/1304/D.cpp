#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> construct(int m, string t){
  vector<pii> seg;
  seg.push_back(mp(1,0));
  for(int i = 0 ; i < t.size(); i ++ ){
    if(t[i] == '<'){
      seg.back().fi ++ ;
    }
    else{
      seg.push_back(mp(1,i+1));
    }
  }
  vector<int> ans;
  int r = m;
  int l;
  for(auto x : seg){
    l = r - x.fi + 1;
    for(int i = l; i <= r; i ++ ){
      ans.push_back(i);
    }
    r = l - 1;
  }
  return ans;
}

vector<int> construct2(int m, string t){
  vector<pii> seg;
  seg.push_back(mp(1,0));
  for(int i = 0 ; i < t.size(); i ++ ){
    if(t[i] == '>'){
      seg.back().fi ++ ;
    }
    else{
      seg.push_back(mp(1,i+1));
    }
  }
  vector<int> ans;
  int l = 0;
  int r = 0;
  for(auto x : seg){
    l = r + 1;
    r = l + x.fi - 1;
    for(int i = r; i >= l ; i -- )
      ans.push_back(i);
  }
  return ans;
}

void solve(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<int> low = construct(n, t);
  vector<int> high = construct2(n,t);
  for(auto x : low) cout << x << " ";
  cout << "\n";
  for(auto x : high) cout << x << " ";
  cout << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ )
    solve();
  return 0;
}