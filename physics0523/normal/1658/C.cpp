#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;cin >> n;
    vector<int> c(n);
    bool fl=true;
    for(int i=0;i<n;i++){cin >> c[i];}
    for(int i=0;i<n;i++){
      if(c[(i+1)%n]-c[i]>1){fl=false;}
    }
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
      if(c[i]>(i+1)){fl=false;}
    }
    if(n>1 && c[1]==1){fl=false;}
    if(fl){cout << "Yes\n";}
    else{cout << "No\n";}
  }
}