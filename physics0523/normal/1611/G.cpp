#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

pi fp[2]={{-5000000,0},{-5000000,1}};
pi lp[2]={{5000000,0},{5000000,1}};

bool connectable(pi a,pi b){
  int vt=abs(a.first-b.first);
  int hr=abs(a.second-b.second);
  return ((hr<=vt) && (hr%2==vt%2));
}

bool insertable(pi a,pi b,pi c){
  return (connectable(a,b) && connectable(b,c));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<vector<int>>> mem(2,vector<vector<int>>(n));
    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=m-1;j>=0;j--){
        if(s[i][j]=='1'){mem[(i+j)%2][i].push_back(j);}
      }
    }
    int res=0;
    for(int p=0;p<2;p++){
      while(1){
        vector<pi> cur;
        for(int i=0;i<n;i++){
          if(!mem[p][i].empty()){
            cur.push_back({mem[p][i].back(),i});
          }
        }
        if(cur.empty()){break;}
        res++;
        sort(cur.begin(),cur.end());
        set<pi> st;
        st.insert(fp[p]);st.insert(lp[p]);
        for(auto &nx : cur){
          pi ny={nx.second,nx.first};
          auto it=st.lower_bound(ny);
          pi c=(*it);
          it--;
          pi a=(*it);
          if(insertable(a,ny,c)){
            st.insert(ny);
            mem[p][ny.first].pop_back();
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}