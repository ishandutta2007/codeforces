#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n+1),res(n+1,0);
    for(int i=1;i<=n;i++){cin >> a[i];}
    for(int i=1;i<=n;i++){
      if(res[i]!=0){continue;}
      int l=1,p=a[i];
      while(p!=i){l++;p=a[p];}
      res[i]=l;p=a[i];
      while(p!=i){res[p]=l;p=a[p];}
    }
    for(int i=1;i<=n;i++){
      if(i!=1){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
}