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
#define len(x) ((ll)(x).size())

const int N = 1005;
int cnt[N];

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int x;
  for(int i = 1;i <= m;i  ++ ){
    cin >> x;
    cnt[x] ++ ;
  }
  int maz = (int)129214;
  for(int i = 1;i <= n;i ++ ){
    maz = min(maz, cnt[i]);
  }
  cout << maz << "\n";
  return 0;
}