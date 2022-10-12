#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> r(n,1),c(m,1);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int v;
        cin >> v;
        if(v==1){r[i]=0;c[j]=0;}
      }
    }
    int p=0,q=0;
    for(auto &nx : r){p+=nx;}
    for(auto &nx : c){q+=nx;}
    p=min(p,q);
    if(p%2){cout << "Ashish\n";}
    else{cout << "Vivek\n";}
  }
  return 0;
}