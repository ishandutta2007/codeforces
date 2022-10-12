#include<bits/stdc++.h>

using namespace std;

long long A007590(long long x){
  return ((x*x)/2);
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
    vector<int> p(n),q(n);
    for(auto &nx : p){cin >> nx;nx--;}
    for(auto &nx : q){cin >> nx;nx--;}
    vector<int> r(n);
    for(int i=0;i<n;i++){r[p[i]]=q[i];}
    vector<int> circ;
    vector<bool> fl(n,false);
    for(int i=0;i<n;i++){
      if(!fl[i]){
        int cl=0,v=i;
        while(!fl[v]){
          fl[v]=true;
          cl++;
          v=r[v];
        }
        circ.push_back(cl);
      }
    }
    long long bar=0;
    for(auto &nx : circ){bar+=(nx/2);}
    long long rem=n-2ll*bar;
    long long res=rem*2ll*bar;
    res+=A007590(2*bar);
    cout << res << '\n';
  }
  return 0;
}