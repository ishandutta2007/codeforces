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
    if(n%4){cout << "NO\n";continue;}
    cout << "YES\n";
    vector<int> a(n);
    int o=-1,e=0;
    for(int i=0;i<(n/2);i++){
      do{e+=2;}while(e%6==0);
      do{o+=2;}while(o%6==3);
      a[i]=e;
      a[i+(n/2)]=o;
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}