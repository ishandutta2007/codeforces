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

int main(){
  fastIO;
  int n;
  cin >> n;
  int cnt1 = 0, cnt0 = 0;
  char c;
  for(int i = 0;i < n;i ++ ){
    cin >> c;
    if(c == '1')
      cnt1 ++ ;
    else
      cnt0 ++; 
  }
  if(cnt1 != 0)
    cout << 1;
  for(int i = 0;i < cnt0 ;i ++ )
    cout << 0;
  return 0;
}