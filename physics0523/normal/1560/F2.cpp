#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  set<long long> st1;
  set<long long> st2;
  for(int i=0;i<10;i++){
    long long v=i;
    st1.insert(i);
    st2.insert(i);
    for(int k=0;k<10;k++){
      v*=10;v+=i;
      st1.insert(v);
      st2.insert(v);
    }
    for(int j=0;j<10;j++){
      for(int h=0;h<(1<<10);h++){
        long long v=0;
        for(int k=0;k<10;k++){
          v*=10;
          if(h&(1<<k)){v+=i;}else{v+=j;}
          st2.insert(v);
        }
      }
    }
  }

  vector<vector<int>> tg(11);
  vector<vector<int>> nd(1024);

  for(int i=0;i<1024;i++){
    int cnt=0;
    for(int j=0;j<10;j++){
      if(i&(1<<j)){cnt++;}
    }
    tg[cnt].push_back(i);

    nd[i].resize(11);
    nd[i][10]=-1;
    int pv=-1;
    for(int j=9;j>=0;j--){
      if(i&(1<<j)){pv=j;}
      nd[i][j]=pv;
    }
  }

  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    if(k==1){cout << (*st1.lower_bound(n)) << '\n';}
    else if(k==2){cout << (*st2.lower_bound(n)) << '\n';}
    else{
      long long res=(*st2.lower_bound(n));
      string s=to_string(n);
      for(auto &nx : tg[k]){
        //cerr << nx << '\n';
        string pf;
        for(int i=0;i<s.size();i++){
          int atk;
          if(i==s.size()-1){atk=nd[nx][s[i]-'0'];}
          else{atk=nd[nx][1+s[i]-'0'];}
          if(atk!=-1){
            string cs=pf;
            cs.push_back('0'+atk);
            for(int j=i+1;j<s.size();j++){cs.push_back('0'+nd[nx][0]);}
            res=min(stoll(cs),res);
          }

          if(nd[nx][s[i]-'0']!=(s[i]-'0')){break;}
          pf.push_back(s[i]);
        }
        if(res==n){break;}
      }
      cout << res << '\n';
    }
  }
  return 0;
}