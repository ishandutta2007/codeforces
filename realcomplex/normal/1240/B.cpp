#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
int fir[N];
int las[N];

void solve(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    fir[i] = -1;
    las[i] = -1;
  }
  int a;
  for(int i = 0 ; i < n; i ++ ){
    cin >> a;
    if(fir[a] == -1) fir[a] = i;
    las[a]=i;
  }
  vector<int> t;
  for(int i = 1; i <= n; i ++ ){
    if(las[i] != -1)
      t.push_back(i);
  }
  int res = (int)t.size() - 1;
  int i = 0;
  int cur;
  while(i < t.size()){
    cur = 1;
    while(i + 1 < t.size() && las[t[i]] < fir[t[i+1]]){
      i++;
      cur++;
    }
    res=min(res,(int)t.size()-cur);
    i++;
  }
  cout << res << "\n";
}

int main(){ 
  fastIO;
  int q;
  cin >> q;
  for(int t = 0; t < q; t ++ ){
    solve();
  }
  return 0;
}