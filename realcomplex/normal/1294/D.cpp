#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 9;
int cnt[N];

int main(){
  fastIO;
  int n, x;
  cin >> n >> x;
  int y;
  priority_queue<pii, vector<pii>, greater<pii>> low;
  for(int i = 0 ; i < x; i ++ )
    low.push(mp(0,i));
  int res;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> y;
    y %= x;
    cnt[y]++;
    low.push(mp(cnt[y],y));
    while(cnt[low.top().se] > low.top().fi){
      low.pop();
    }
    res = low.top().fi * x + low.top().se;
    cout << res << "\n";
  }
  return 0;
}