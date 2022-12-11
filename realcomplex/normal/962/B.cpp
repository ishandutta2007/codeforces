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

int main(){
  fastIO;
  int n,a,b;
  cin >> n >> a >> b;
  char f[n];
  vector<int>fl;
  for(int i = 0;i < n; i ++ ){
    cin >> f[i];
    if(f[i] == '.'){
      if(i == 0)
        fl.push_back(1);
      else
        if(f[i - 1] == '*')
          fl.push_back(1);
        else
          fl[fl.size() - 1] ++ ;
    }
  }
  sort(fl.begin(),fl.end());
  int b1,b2;
  int ans = 0;
  for(auto x : fl){
    if(a > b)
      swap(a,b);
    b1 = (x + 1) / 2;
    b2 = x - b1;
    ans += min(a, b2);
    a = max(0, a - b2);
    ans += min(b, b1);
    b = max(0, b - b1);
  }
  cout << ans;
  return 0;
}