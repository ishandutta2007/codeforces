#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> a;
  int x;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x;
    a.push_back(mp(x,i));
  }
  sort(a.begin(), a.end());
  int idx = 0;
  int total = 0;
  for(int i = n-1; i >= 0 ; i--){
    total += a[i].fi * idx + 1;
    idx ++ ;
  }
  cout << total << "\n";
  for(int i = n-1;i>=0;i--)
    cout << a[i].se + 1 << " ";
  return 0;
}