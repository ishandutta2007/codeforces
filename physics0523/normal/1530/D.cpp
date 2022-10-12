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
    vector<int> p(n+1);
    set<int> st;
    for(int i=1;i<=n;i++){
      cin >> p[i];
      st.insert(p[i]);
    }
    if(st.size()==n){
      cout << n << '\n';
      for(int i=1;i<=n;i++){
        if(i-1){cout << ' ';}
        cout << p[i];
      }cout << '\n';
      continue;
    }
    if(st.size()==n-1){
      set<int> lis;
      for(int i=1;i<=n;i++){lis.insert(i);}
      for(int i=1;i<=n;i++){lis.erase(p[i]);}
      int rv=(*lis.begin());
      lis.clear();
      int db;
      map<int,int> mp;
      for(int i=1;i<=n;i++){
        mp[p[i]]++;
        if(mp[p[i]]>=2){db=p[i];}
      }
      for(int i=1;i<=n;i++){
        if(p[i]==db && i!=rv){p[i]=rv;break;}
      }
      cout << n-1 << '\n';
      for(int i=1;i<=n;i++){
        if(i-1){cout << ' ';}
        cout << p[i];
      }cout << '\n';
      continue;
    }

    vector<int> res(n+1,0);
    int val=0;

    set<int> lis;
    for(int i=1;i<=n;i++){lis.insert(i);}

    for(int i=1;i<=n;i++){
      if(val!=n-2 && lis.find(p[i])!=lis.end()){
        lis.erase(p[i]);
        res[i]=p[i];
        val++;
      }
    }
    //for(int i=1;i<=n;i++){cout << res[i] << ' ';}cout << '\n';
    for(int i=1;i<=n;i++){
      if(res[i]>0){continue;}
      if(lis.find(i)!=lis.end()){
        lis.erase(i);
        res[i]=-i;
      }
    }
    //for(int i=1;i<=n;i++){cout << res[i] << ' ';}cout << '\n';
    vector<int> sl;
    for(int i=1;i<=n;i++){
      if(res[i]==0){
        int od=(*lis.begin());
        lis.erase(od);
        res[i]=(-od);
      }
      if(res[i]<0){sl.push_back(-res[i]);}
    }
    //for(int i=1;i<=n;i++){cout << res[i] << ' ';}cout << '\n';
    int pt=1;
    for(int i=1;i<=n;i++){
      if(res[i]<0){
        res[i]=sl[pt%sl.size()];
        pt++;
      }
    }

    cout << val << '\n';
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}