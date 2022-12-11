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

const int D = (int)1e5 + 9;
vector<int>ans[D];

int main(){
  fastIO;
  int n;
  cin >> n;
  pii bl[n];
  for(int i = 0; i< n; i ++ ){
    cin >> bl[i].fi;
    bl[i].se = i;
  }
  sort(bl , bl + n);
  int las = -1;
  for(int i = n - 1;i >= 0 ;i -- ){
    las = max(las, bl[i].se);
    ans[las].push_back(bl[i].fi);
  }
  for(int i = 0 ; i< n; i ++ ){
    for(auto x : ans[i] )
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}