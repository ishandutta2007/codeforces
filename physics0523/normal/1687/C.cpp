#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<long long>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      long long b;
      cin >> b;
      a[i]-=b;
    }

    long long v=0;
    vector<long long> rw(n+1,0);
    for(int i=0;i<n;i++){
      v+=a[i];
      rw[i+1]=v;
    }

    // for(auto &nx : rw){cout << nx << ' ';}cout << '\n';
    vector<long long> l(k),r(k);
    Graph g(n+1);
    for(long long i=0;i<k;i++){
      cin >> l[i] >> r[i];
      l[i]--;
      g[l[i]].push_back(i);
      g[r[i]].push_back(i);
    }

    queue<long long> q;
    set<long long> st;
    vector<bool> used(k,false);
    for(long long i=0;i<=n;i++){
      if(rw[i]==0){
        for(auto &nx : g[i]){
          if(rw[l[nx]]==0 && rw[r[nx]]==0 && !used[nx]){
            q.push(nx);
            used[nx]=true;
          }
        }
      }
      else{st.insert(i);}
    }

    st.insert(1e18);
    while(!q.empty()){
      long long od=q.front();q.pop();
      while(1){
        auto it=st.lower_bound(l[od]);
        long long cur=(*it);
        if(cur>r[od]){break;}
        st.erase(it);
        rw[cur]=0;
        for(auto &nx : g[cur]){
          if(rw[l[nx]]==0 && rw[r[nx]]==0 && !used[nx]){
            q.push(nx);
            used[nx]=true;
          }
        }
      }
    }

    bool jud=true;
    for(auto &nx : rw){
      if(nx!=0){jud=false;}
    }
    if(jud){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}