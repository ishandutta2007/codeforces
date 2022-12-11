#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int t = 0; t < testc; t ++ ){
    int n;
    cin >> n;
    vector<pii> f;
    for(int x = 2; x * x <= n; x ++ ){
      if(n % x == 0){
        f.push_back(mp(x,0));
        while(n % x == 0){
          f[(int)f.size()-1].se++;
          n /= x;
        }
      }
    }
    if(n > 1)
      f.push_back(mp(n,1));
    if(f.size() >= 3){
      cout << "YES\n";
      int x = 1;
      for(int i = 0 ; i < 2; i ++ ){
        x=1;
        for(int j = 0 ; j < f[i].se; j ++ ){
          x *= f[i].fi;
        }
        cout << x << " ";
      }
      x=1;
      for(int i = 2; i < f.size(); i ++ ){
        for(int j = 0 ; j < f[i].se; j ++ )
          x *= f[i].fi;
      }
      cout << x << "\n";
    }
    else if(f.size() == 2){
      if(f[0].se + f[1].se <= 3){
        cout << "NO\n";
      }
      else{
        cout << "YES\n";
        cout << f[0].fi << " " << f[1].fi << " ";
        int x = 1;
        for(int i = 0 ; i < 2; i ++ )
          for(int j = 1; j < f[i].se; j ++ )
            x *= f[i].fi;
        cout << x << "\n";
      }
    }
    else{
      if(f[0].se >= 6){
        cout << "YES\n";
        cout << f[0].fi << " " << f[0].fi * f[0].fi << " ";
        int x = 1;
        for(int i = 0; i < f[0].se - 3; i ++ ){
          x *= f[0].fi;
        }
        cout << x << "\n";
      }
      else{
        cout << "NO\n";
      }
    }
  }
  return 0;
}