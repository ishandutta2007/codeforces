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

const int N = (int)2e5 + 2194;
int order[N];

int main(){
  fastIO;
  int n,m,k;
  cin >> n >> m >> k;
  int ti[n];
  for(int i = 0;i<n;i++)cin >> ti[i];
  sort(ti,ti + n);
  int p = 0;
  int ans = 0;
  for(int i = 0;i<n;i++){
    p++;
    order[p] = ti[i]; 
    if(p < k)
      continue;
    if(order[p] - order[p - k + 1] + 1 <= m){
      ans++;
      p--;
    }
  }
  cout << ans;
  return 0;
}