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
    vector<int> od,ev;
    for(int i=1;i<=2*n;i++){
      int v;
      cin >> v;
      if(v%2){od.push_back(i);}
      else{ev.push_back(i);}
    }
    for(int i=0;i<n-1;i++){
      if(od.size()>=2){
        int p=od.back();od.pop_back();
        int q=od.back();od.pop_back();
        cout << p << ' ' << q << '\n';
      }
      else{
        int p=ev.back();ev.pop_back();
        int q=ev.back();ev.pop_back();
        cout << p << ' ' << q << '\n';
      }
    }
  }
  return 0;
}