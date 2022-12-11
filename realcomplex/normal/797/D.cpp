#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int pl[N],pr[N];
int vl[N];
bool has[N];
int pos[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> chk;
  for(int i = 1; i <= n; i ++ ){
    cin >> vl[i] >> pl[i] >> pr[i];
    chk.push_back(mp(vl[i],i));
    if(pl[i] != -1) has[pl[i]] = true;
    if(pr[i] != -1) has[pr[i]] = true;
    pos[i] = -1;
  }
  int root = -1;
  for(int i = 1; i <= n; i ++ )
    if(!has[i]) root = i;
  sort(chk.begin(), chk.end());
  vector<int> path;
  int cr = root;
  while(cr != -1){
    pos[cr] = path.size();
    path.push_back(cr);
    cr = pl[cr];
  }
  int x;
  int p;
  int low;
  int ans = 0;
  for(int i = 0 ; i < n; i ++ ){
    if(i == n - 1 || chk[i].fi != chk[i + 1].fi){
      x = chk[i].fi;
      p = i;
      vector<int> cur;
      while(p >= 0 && chk[p].fi == chk[i].fi){
        cur.push_back(chk[p].se);
        p--;
      }
      low = cur[0];
      for(int j = 1; j < cur.size(); j ++ ){
        if(pos[cur[j]] == -1) continue;
        if(pos[low] > pos[cur[j]] || pos[low] == -1){
          low = cur[j];
        }
      }
      if(pos[low] == -1){
        ans += cur.size() ;
      }
      else{
        while(path.size() > pos[low] + 1){
          pos[path.back()] = -1;
          path.pop_back();
        }
        low = pr[low];
        while(low != -1){
          pos[low] = path.size();
          path.push_back(low);
          if(x < vl[low]) low = pl[low];
          else low = pr[low];
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}