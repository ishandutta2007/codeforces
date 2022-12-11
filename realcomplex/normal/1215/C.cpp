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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> ab, ba;
  for(int i = 0 ; i < n; i ++ ){
    if(a[i] != b[i]){
      if(a[i] == 'a')ab.push_back(i);
      else ba.push_back(i);
    }
  }
  int sum = (int)ab.size() + (int)ba.size();
  if(sum % 2 == 1){
    cout << -1;
    return 0;
  }
  int k = ab.size();
  int m1 = k/2;
  int j;
  vector<pii> opr;
  for(int i = 0 ; i < k ; i ++ ){
    j = k - i - 1;
    if(i < j){
      opr.push_back(mp(ab[i], ab[j]));
    }
  }
  k = ba.size();
  int m2 = k/2;
  for(int i = 0 ; i < k ; i ++ ){
    j = k - i - 1;
    if(i < j){
      opr.push_back(mp(ba[i], ba[j]));
    }
  }
  if(k % 2 == 1){
    int p1 = ab[m1];
    int p2 = ba[m2];
    opr.push_back(mp(p1,p1));
    opr.push_back(mp(p1,p2));
  }
  cout << opr.size() << "\n";
  for(auto x : opr)
    cout << x.fi + 1 << " " << x.se + 1 << "\n";
  return 0;
}