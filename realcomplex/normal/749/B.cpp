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

int main(){
  fastIO;
  pii cor[3];
  for(int i = 0;i < 3;i ++)
    cin >>  cor[i].fi  >> cor[i].se;
  sort(cor, cor + 3);
  set<pii>ans;
  int dx,dy;
  do{
    dx = cor[0].fi - cor[1].fi;
    dy = cor[0].se - cor[1].se;
    ans.insert(mp(cor[2].fi + dx,cor[2].se + dy));
  }while(next_permutation(cor,cor + 3));
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}