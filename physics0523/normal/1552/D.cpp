#include<bits/stdc++.h>

using namespace std;

int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    set<int> a;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v!=0){a.insert(abs(v));}
    }
    if(a.size()<n){cout << "YES\n";continue;}
    vector<int> val;
    for(auto &nx : a){val.push_back(nx);}
    int ts=pow(3,n);
    bool fl=false;
    for(int i=1;i<ts;i++){
      int sig=0,pt=i;
      for(int j=0;j<n;j++){
        if(pt%3==1){sig+=val[j];}
        if(pt%3==2){sig-=val[j];}
        pt/=3;
      }
      if(sig==0){fl=true;break;}
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}