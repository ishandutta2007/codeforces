#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

void rev(string &s,int p,int q){
  while(p<q){
    swap(s[p],s[q]);
    p++;q--;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s,tg;
    cin >> s;
    int fl=(n/2)-k+1;
    for(int i=0;i<fl;i++){tg.push_back('(');}
    for(int i=0;i<fl;i++){tg.push_back(')');}
    for(int i=1;i<k;i++){
      tg.push_back('(');
      tg.push_back(')');
    }
    vector<pi> res;
    for(int i=0;i<n;i++){
      if(s[i]!=tg[i]){
        int pt;
        for(int j=i;j<n;j++){
          if(s[j]==tg[i]){pt=j;break;}
        }
        res.push_back({i+1,pt+1});
        rev(s,i,pt);
      }
    }
    //cout << tg << '\n';
    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.first << ' ';
      cout << nx.second << '\n';
    }
  }
  return 0;
}