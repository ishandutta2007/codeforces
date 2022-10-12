#include<bits/stdc++.h>

using namespace std;

#define BIG 20000000

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> l(n,0);
  for(int i=1;i<n;i++){cin >> l[i];}
  vector<vector<long long>> mem(n,vector<long long>(1,0));
  vector<vector<long long>> rw(n);
  for(int i=n-1;i>0;i--){
    for(auto &nx : mem[i]){
      mem[(i-1)/2].push_back(nx+l[i]);
    }
  }
  for(int i=0;i<n;i++){
    sort(mem[i].begin(),mem[i].end());
    rw[i]=mem[i];
    for(int j=1;j<rw[i].size();j++){rw[i][j]+=rw[i][j-1];}
  }

  for(int i=0;i<m;i++){
    long long a,h;
    cin >> a >> h;
    a--;
    long long res=0;
    long long lp=distance(mem[a].begin(),lower_bound(mem[a].begin(),mem[a].end(),h));
    if(lp>0){res+=lp*h-rw[a][lp-1];}
    set<int> st;
    st.insert(a);
    h-=l[a];a=(a-1)/2;
    while(h>0 && st.find(0)==st.end()){
      res+=h;
      int ch=a*2+1;
      if(st.find(ch)!=st.end()){ch++;}
      if(ch<n){
        long long lh=h-l[ch];
        if(lh>0){
          long long clp=distance(mem[ch].begin(),lower_bound(mem[ch].begin(),mem[ch].end(),lh));
          if(clp>0){res+=clp*lh-rw[ch][clp-1];}
        }
      }
      st.insert(a);
      h-=l[a];a=(a-1)/2;
    }
    cout << res << '\n';
  }
  return 0;
}