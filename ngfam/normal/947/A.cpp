#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int X;
int p[N];
list < int > prime[N];

int main(){

  cin >> X;

  for(int i = 2; i < N; ++i){
    if(p[i]) continue;
    for(int j = i + i; j < N; j += i){
      p[j] = 1;
      prime[j].push_back(i);
    }
  }

  int ans = X;


  for(int i = X - prime[X].back() + 1; i <= X; ++i){
    if(!p[i]) continue;
    ans = min(ans, i - prime[i].back() + 1);
  }

  cout << ans;

	return 0;
}