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
    if(n%2==1){cout << "Bob\n";}
    else{
      int fl=0;
      for(int i=1;i<=29;i+=2){
        if(n==(1<<i)){fl=1;}
      }
      if(fl){cout << "Bob\n";}else{cout << "Alice\n";}
    }
  }
  return 0;
}