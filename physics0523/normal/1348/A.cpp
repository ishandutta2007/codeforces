#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int res=((1<<n)-1);
    res-=2*(((1<<(n/2))-1)<<((n/2)-1));
    cout << res*2 << '\n';
  }
  return 0;
}