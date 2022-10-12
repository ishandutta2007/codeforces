#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,u,v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    int fl=2;
    for(int i=1;i<n;i++){
      if(a[i]!=a[i-1]){fl=min(fl,1);}
      if(abs(a[i]-a[i-1])>=2){fl=min(fl,0);}
    }
    if(fl==0){cout << "0\n";}
    else if(fl==1){cout << min(u,v) << '\n';}
    else{cout << min(u+v,2*v) <<'\n';}
  }
  return 0;
}