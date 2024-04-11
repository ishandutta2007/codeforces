#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    long long x;
    cin >> x;
    for(auto &nx : a){nx-=x;}

    long long res=0,cur=0,llim,sz=0;
    a.push_back(-1e18);
    for(int i=0;i<=n;i++){
      long long nf=cur+a[i];
      if(sz==0){
        llim=cur;
        res++;
        sz++;
      }
      else{
        if(llim>nf){sz=0;}
        else{res++;sz++;}
      }
      llim=max(llim,cur);
      cur=nf;
      if(i==n-1 && sz==0){break;}
    }
    cout << res << '\n';
  }
  return 0;
}