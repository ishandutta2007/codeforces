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
    int a=1;
    for(int i=0;i<n;i++){
      int b=a+(1<<i);
      if((a+b)%2==0){a=b;}
    }
    cout << a << '\n';
  }
  return 0;
}