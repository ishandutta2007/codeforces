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

const int N = 105;
int a[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1;i<=n;i++){
    cin >> a[i];
    sum += a[i];
  }
  if(sum!=0){
    cout << "YES\n" << 1 << "\n" << 1 << " " << n << "\n";
    return 0;
  }
  int x = 0;
  for(int i = 1;i<=n;i++){
    x+=a[i];
    if(x != 0 and sum-x != 0){
      cout << "YES\n";
      cout << 2 << "\n" << 1 << " " << i << "\n" << i+1 << " " << n << "\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}