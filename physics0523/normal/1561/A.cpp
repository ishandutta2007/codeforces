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
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int res=0;;res++){
      bool fl=true;
      for(int i=0;i<n;i++){
        if(i+1!=a[i]){fl=false;}
      }
      if(fl){cout << res << '\n';break;}
      for(int i=0;i<(n-1);i++){
        if(i%2==res%2){
          if(a[i]>a[i+1]){swap(a[i],a[i+1]);}
        }
      }
    }
  }
  return 0;
}