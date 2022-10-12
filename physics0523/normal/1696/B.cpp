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
    int l=1e9,r=-1e9;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(a[i]>0){
        l=min(l,i);
        r=max(r,i);
      }
    }
    if(l>5e8){cout << "0\n";continue;}
    bool ok=true;
    for(int i=l;i<=r;i++){
      if(a[i]==0){ok=false;break;}
    }
    if(ok){cout << "1\n";}
    else{cout << "2\n";}
  }
  return 0;
}