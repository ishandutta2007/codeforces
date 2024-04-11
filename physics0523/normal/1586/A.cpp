#include<bits/stdc++.h>

using namespace std;

bool iscomp(int x){
  for(int i=2;i*i<=x;i++){
    if(x%i==0){return true;}
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int sig=0;
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    if(iscomp(sig)){
      cout << n << '\n';
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << i+1;
      }cout << '\n';
      continue;
    }

    int x=-1,y,z;
    for(int i=0;i<n;i++){
      if(iscomp(sig-a[i])){x=i;break;}
    }
    if(x!=-1){
      bool fl=false;
      cout << n-1 << '\n';
      for(int i=0;i<n;i++){
        if(i==x){continue;}
        if(fl){cout << ' ';}
        fl=true;
        cout << i+1;
      }cout << '\n';
      continue;
    }

    x=-1,y=-1;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(iscomp(sig-a[i]-a[j])){x=i;y=j;}
      }
    }
    if(x!=-1){
      bool fl=false;
      cout << n-2 << '\n';
      for(int i=0;i<n;i++){
        if(i==x || i==y){continue;}
        if(fl){cout << ' ';}
        fl=true;
        cout << i+1;
      }cout << '\n';
      continue;
    }
    
    x=-1;y=-1;z=-1;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
          if(iscomp(sig-a[i]-a[j]-a[k])){x=i;y=j;z=k;}
        }
      }
    }
    bool fl=false;
    cout << n-3 << '\n';
    for(int i=0;i<n;i++){
      if(i==x || i==y || i==z){continue;}
      if(fl){cout << ' ';}
      fl=true;
      cout << i+1;
    }cout << '\n';
  }
  return 0;
}