#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int st=0,fi=1000000007;
  while(st<=fi){
    int te=(st+fi)/2;
    bool isok=false;
    // odd
    int sz=0;
    for(int i=0;i<n;i++){
      if(sz%2==0){
        if(a[i]<=te){sz++;}
      }
      else{sz++;}
    }
    if(sz>=m){isok=true;}
    
    // even
    sz=0;
    for(int i=0;i<n;i++){
      if(sz%2==1){
        if(a[i]<=te){sz++;}
      }
      else{sz++;}
    }
    if(sz>=m){isok=true;}

    if(isok){fi=te-1;}
    else{st=te+1;}
  }
  cout << st << '\n';
  return 0;
}