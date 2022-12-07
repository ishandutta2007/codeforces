#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n;
int arr[N];
int prime[N];
int idx[N];
vector < int > lst;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif
  cin >> n;
  int answer = 1;
  for(int i = 2; i <= n + 1; ++i){
    if(prime[i] == 0){
      prime[i] = 1;
      lst.push_back(i);
      for(int j = i + i; j <= n + 1; j += i){
        prime[j] = 2;
        answer = 2;
      }
    }
  }
  cout << answer << endl;
  for(int i = 2; i <= n + 1; ++i){
    cout << prime[i] << " ";
  }
  return 0;
}