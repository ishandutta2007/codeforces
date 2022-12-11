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

const int N = (int)1e5 + 1234;
ll arr[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll s = 0, p = 0;
  for(int i = 1;i<=n;i++){
    cin >> arr[i];
  }
  for(int i = 2;i<=n;i++){
    if ( i % 2 == 0){
      s = max(s + ab(arr[i] - arr[i-1]),ab(arr[i] - arr[i-1])); 
    }
    else{
      s = max(s - ab(arr[i] - arr[i-1]),-ab(arr[i] - arr[i-1]));
    }
    p = max(s,p);
  }
  s = 0;
  for(int i = 3;i<=n;i++){
    if ( i % 2 == 1){
      s = max(s + ab(arr[i] - arr[i-1]),ab(arr[i] - arr[i-1])); 
    }
    else{
      s = max(s - ab(arr[i] - arr[i-1]),-ab(arr[i] - arr[i-1]));
    }
    p = max(s,p);
  }
  cout << p;
  return 0;
}