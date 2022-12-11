#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int pa[N];
int pb[N];

map<int,int>cnt;

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  for(int i = 0; i < n; i ++ ){
    cin >> x;
    pa[x]=i;
  }
  for(int i = 0 ; i < n; i ++ ){
    cin >> x;
    pb[x]=i;
  }
  int nd;
  int ans = 0;
  for(int i = 1; i <= n; i ++ ){
    nd = (pa[i]-pb[i]+n)%n;
    cnt[nd]++;
    ans=max(ans,cnt[nd]);
  }
  cout << ans << "\n";
  return 0;
}