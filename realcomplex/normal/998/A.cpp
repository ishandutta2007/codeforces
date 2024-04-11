#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
  fastIO;  
  int n;
  cin >> n;
  if(n == 1){
    cout << -1;
    return 0;
  }
  pii a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i].fi;
    a[i].se = i + 1;
  }
  sort(a, a + n);
  vector<int> ix;
  int t1 = 0, t2 = a[0].fi;
  for(int i = 1;i < n;i ++ ){
    t1 += a[i].fi;
    ix.push_back(a[i].se);
  }
  if(t1 == t2)
    cout << -1;
  else{
    cout << ix.size() << "\n";
    for(auto x : ix)
      cout << x << " ";
  }
  return 0;
}