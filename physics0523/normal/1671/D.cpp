#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long f(vector<long long> &a){
  int n=a.size();
  long long res=0;
  for(int i=0;i<n-1;i++){res+=abs(a[i+1]-a[i]);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    long long res=8e18;
    long long orgf=f(a);
    vector<pl> v1,vx;
    for(long long i=1;i<n;i++){
      long long org=abs(a[i-1]-a[i]);
      v1.push_back({abs(a[i-1]-1)+abs(1-a[i])-org,i});
      vx.push_back({abs(a[i-1]-x)+abs(x-a[i])-org,i});
    }
    v1.push_back({abs(1-a[0]),0});
    v1.push_back({abs(1-a[n-1]),n});
    vx.push_back({abs(x-a[0]),0});
    vx.push_back({abs(x-a[n-1]),n});

    sort(v1.begin(),v1.end());
    sort(vx.begin(),vx.end());
    for(auto &nx : v1){
      for(auto &ny : vx){
        if(nx.second==ny.second){continue;}
        res=min(orgf+nx.first+ny.first,res);
        break;
      }
    }
    res=min(orgf+abs(1-x)+abs(x-a[0]),res);
    res=min(orgf+abs(x-1)+abs(1-a[0]),res);
    res=min(orgf+abs(a[n-1]-1)+abs(1-x),res);
    res=min(orgf+abs(a[n-1]-x)+abs(x-1),res);
    for(int i=1;i<n;i++){
      long long org=abs(a[i-1]-a[i]);
      res=min(orgf-org+abs(a[i-1]-1)+abs(1-x)+abs(x-a[i]),res);
      res=min(orgf-org+abs(a[i-1]-x)+abs(x-1)+abs(1-a[i]),res);
    }
    cout << res << '\n';
  }
  return 0;
}