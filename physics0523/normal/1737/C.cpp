#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(3);
    vector<int> q(3);
    vector<int> a(2,0);
    vector<int> b(2,0);
    bool lock=false;
    map<pi,int> mp;
    for(int i=0;i<3;i++){
      cin >> p[i] >> q[i];
      a[p[i]%2]++;
      b[q[i]%2]++;
      mp[{p[i],q[i]}]++;
    }
    int x,y;
    cin >> x >> y;

    if(mp[{1,1}]==1 && mp[{1,2}]==1 && mp[{2,1}]==1){lock=true;}
    if(mp[{1,n}]==1 && mp[{1,n-1}]==1 && mp[{2,n}]==1){lock=true;}
    if(mp[{n,1}]==1 && mp[{n,2}]==1 && mp[{n-1,1}]==1){lock=true;}
    if(mp[{n,n}]==1 && mp[{n,n-1}]==1 && mp[{n-1,n}]==1){lock=true;}

    if(lock){
      int okx,oky;
      if(mp[{1,1}]==1){okx=1;oky=1;}
      if(mp[{1,n}]==1){okx=1;oky=n;}
      if(mp[{n,1}]==1){okx=n;oky=1;}
      if(mp[{n,n}]==1){okx=n;oky=n;}
      
      if(x==okx || y==oky){cout << "YES\n";}
      else{cout << "NO\n";}
      continue;
    }

    if(a[x%2]==1 && b[y%2]==1){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}