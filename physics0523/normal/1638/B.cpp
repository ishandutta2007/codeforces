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
    int fl=0;
    for(auto &nx : a){
      cin >> nx;
      fl|=(1<<(nx%2));
    }
    if(fl!=3){
      bool isok=true;
      for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){isok=false;}
      }
      if(isok){cout << "Yes\n";}
      else{cout << "No\n";}
    }
    else{
      vector<int> e,o;
      for(int i=0;i<n;i++){
        if(a[i]%2){o.push_back(a[i]);}
        else{e.push_back(a[i]);}
      }
      vector<int> se=e,so=o;
      sort(se.begin(),se.end());
      sort(so.begin(),so.end());
      if(e==se && o==so){cout << "Yes\n";}
      else{cout << "No\n";}
    }
  }
  return 0;
}