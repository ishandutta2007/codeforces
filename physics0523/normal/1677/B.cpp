#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    string s;
    cin >> n >> m >> s;
    int l=s.size();
    vector<int> rw(2*l+1,0);
    for(int i=0;i<l;i++){
      rw[l+i+1]=rw[l+i];
      rw[l+i+1]+=(s[i]-'0');
    }

    vector<int> f(l,0),g(l,0);
    for(int i=0;i<m;i++){
      for(int j=i;j<l;j+=m){
        if(s[j]=='1'){f[j]++;break;}
      }
    }
    for(int i=1;i<l;i++){f[i]+=f[i-1];}

    for(int i=1;i<=l;i++){
      if(rw[l+i]-rw[l+i-m]>0){
        g[i-1]++;
      }
    }
    for(int i=m;i<l;i++){g[i]+=g[i-m];}

    for(int i=0;i<l;i++){
      if(i){cout << ' ';}
      cout << f[i]+g[i];
    }cout << '\n';
  }
  return 0;
}