#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> res;
    bool ng=false;
    for(int i=1;i<=n;i++){
      int x=ceil(l,i)*i;
      if(x>r){ng=true;break;}
      res.push_back(x);
    }
    if(ng){cout << "NO\n";continue;}
    cout << "YES\n";
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}