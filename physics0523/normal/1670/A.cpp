#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,neg=0;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
      if(nx<0){nx*=-1;neg++;}
    }
    for(int i=0;i<neg;i++){a[i]*=-1;}
    bool isok=true;
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){isok=false;break;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}