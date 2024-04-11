#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

int dig[N];
int in[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  char d;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> d;
    in[i] = d - '0';
  }
  for(int i = 0 ; i < k ; i ++ ){
    dig[i] = in[i];
  }
  bool ok=true;
  for(int j = 0 ; j < n ; j ++ ){
    if(in[j]<dig[j%k]){
      break;
    }
    else if(in[j]>dig[j%k]){
      ok=false;
      break;
    }
  }
  if(!ok){
    for(int j = k - 1; j >= 0 ; j -- ){
      if(dig[j] < 9){
        dig[j]++;
        break;
      }
      else{
        dig[j]=0;
      }
    }
  }
  cout << n << "\n";
  for(int i = 0 ; i < n ; i ++ ){
    cout << dig[i % k];
  }
  return 0;
}