#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<bool> fl(1048576,false);
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    fl[v]=true;
  }

  n*=-1;
  for(int i=1048575;i>=1;i--){
    if(fl[i]){n++;continue;}
    int g=-1;
    for(int j=i;j<1048576;j+=i){
      if(fl[j]){
        if(g==-1){g=j/i;}
        else{g=gcd(g,j/i);}
      }
    }
    if(g==1){n++;fl[i]=true;}
  }
  cout << n << '\n';
  return 0;
}