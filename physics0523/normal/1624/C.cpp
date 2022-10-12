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
    vector<int> bk(n+1,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      while(v>n){v/=2;}
      bk[v]++;
    }
    bool iserr=false;
    for(int i=n;i>=1;i--){
      while(bk[i]>1){bk[i]--;bk[(i/2)]++;}
      if(bk[i]==0){iserr=true;}
    }
    if(iserr){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}