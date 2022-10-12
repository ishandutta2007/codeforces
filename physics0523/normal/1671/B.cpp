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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    bool fl=false;
    for(int d=-1;d<=1;d++){
      for(int i=0;i<n;i++){
        int tg=a[0]+i+d;
        if(abs(a[i]-tg)>1){break;}
        if(i==n-1){fl=true;}
      }
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}