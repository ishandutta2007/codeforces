#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x,y;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      x+=v;
    }
    if(x%2==y%2){cout << "Alice\n";}
    else{cout << "Bob\n";}
  }
  return 0;
}