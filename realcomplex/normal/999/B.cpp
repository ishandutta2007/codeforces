#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  char arr[n];
  for(int i = 0;i < n;i ++ ){
    cin >> arr[i];
  }
  for(int i = 1;i <= n;i ++ ){
    if(n % i == 0){
      reverse(arr, arr + i);
    }
  }
  for(int i = 0;i < n;i ++ )
    cout << arr[i];
  return 0;
}