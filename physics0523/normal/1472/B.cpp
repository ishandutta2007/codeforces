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
    int a=0,b=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v==1){a++;}else{b++;}
    }
    if(a%2){cout << "NO\n";}
    else if(((a+2*b)/2)%2==1 && a==0){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}