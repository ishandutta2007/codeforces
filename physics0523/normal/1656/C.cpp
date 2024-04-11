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
    if(n==1){cout << "YES\n";continue;}

    sort(a.begin(),a.end());
    if(a[0]>=2){cout << "YES\n";continue;}
    if(a[0]==a[n-1]){cout << "YES\n";continue;}

    int fl=0;
    for(int i=0;i<n;i++){
      if(a[i]==0){fl|=1;}
      if(a[i]==1){fl|=2;}
    }
    if(fl==3){cout << "NO\n";continue;}
    if(a[0]==0){cout << "YES\n";continue;}
    bool isok=true;
    for(int i=1;i<n;i++){
      if(a[i]-a[i-1]==1){isok=false;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}