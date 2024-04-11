#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++){
      cin >> x[i] >> y[i];
    }
    if(n==1){cout << "0\n";continue;}
    int res=inf;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((abs(x[i]-x[j])+abs(y[i]-y[j]))>k){break;}
        if(j==n-1){res=1;}
      }
    }
    if(res==inf){cout << "-1\n";}
    else{cout << res << '\n';}
  }
}