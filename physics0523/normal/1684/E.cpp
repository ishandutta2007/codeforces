#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;

    map<int,int> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
    }

    vector<int> bk(n+1,0);
    set<int> st;
    int ldi=0;
    for(auto &nx : mp){
      bk[nx.second]++;
      ldi++;
    }
    for(int i=1;i<=n;i++){
      if(bk[i]>0){st.insert(i);}
    }

    int res=1e9,skip=0;
    for(int mx=0;(mx<=n && skip<=k);mx++){
      int di=mx;
      int kill=0,rem=k;
      for(auto &nx : st){
        if(bk[nx]*nx>=rem){
          kill+=(rem/nx);
          break;
        }
        else{
          kill+=bk[nx];
          rem-=(bk[nx]*nx);
        }
      }
      di+=max(0,ldi-kill);
      di=max(1,di);
      res=min(res,di-mx);
      if(mp[mx]==0){skip++;}
      else{
        bk[mp[mx]]--;
        if(bk[mp[mx]]==0){st.erase(mp[mx]);}
        ldi--;
      }
    }
    cout << res << '\n';
  }
  return 0;
}