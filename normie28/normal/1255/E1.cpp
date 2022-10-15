#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl
 
const int maxn = 5e5 + 5;
 
int n;
int a[maxn];
vector<int> v;
int N;
int tot = 0;
ll ans = 5e18;
 
ll go(int size) {
  ll moves = 0;
  for (int i=0; i<N; i+=size) {
    int l = i; int r = i+size;
    int mid = (l+r)/2;
    for (int j=l; j<r; j++) {
      moves += abs(v[mid]-v[j]);
    }
  }
  return moves;
}
 
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
 
  cin>>n;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    if (a[i] ==1) {
      v.push_back(i);
    }
 
    tot += a[i];
  }
  N = v.size();
 
  for (int f=2; f<=tot; f++) {
    if (tot%f) continue;
    ans = min(ans, go(f));
  }
 
  if (ans == 5e18) ans = -1;
 
  cout<<ans<<endl;
}