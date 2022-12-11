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

const int M = 12;
int mt[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  n -- ;
  int x = mt[n];
  int ans = 1;
  --m;
  for(int i = 1;i < x;i ++ ){
    m ++ ;
    m %= 7;
    if (m == 0)
      ans++;
  }
  cout << ans << "\n";
  return 0;
}