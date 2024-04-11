#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    bool isok=false;
    for(long long i=0;i<11;i++){
      long long m=n-111*i;
      if(m>=0 && m%11==0){isok=true;}
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}