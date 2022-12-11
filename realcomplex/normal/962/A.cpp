#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n;
  cin >> n;
  int sum = 0;
  int arr[n];
  for(int i = 0;i < n; i ++ ){
    cin >> arr[i];
    sum += arr[i];
  }
  sum = (sum + 1) / 2;
  for(int i = 0;i < n;i ++ ){
    sum -= arr[i];
    if(sum <= 0){
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}