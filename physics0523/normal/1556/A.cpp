#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    if(a==0 && b==0){
      cout << "0\n";continue;
    }
    if(a==b){
      cout << "1\n";continue;
    }
    if((a+b)%2==0){
      cout << "2\n";continue;
    }
    cout << "-1\n";
  }
  return 0;
}