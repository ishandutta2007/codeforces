#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

vector<pii> data;

bool correct(int cnt){
  for(auto x : data){
    if((x.fi + cnt - 1) / cnt != x.se)
      return false;
  }
  return true;
}

int main(){
  fastIO;
  int m,n;
  cin >> m >> n;
  int ki,fi;
  for(int i = 0 ; i < n; i ++ ){
    cin >> ki >> fi;
    data.push_back(mp(ki,fi));
  }
  int ans = -1;
  for(int j = 1;j <= 101;j ++ ){
    if(correct(j)){
      if(ans == -1){
        ans = (m + j - 1) / j;
      }
      else if(ans != (m + j - 1) / j){
        cout << -1 << "\n";
        return 0;
      }
    }
  }
  cout << ans;
  return 0;
}