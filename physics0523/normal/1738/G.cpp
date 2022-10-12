// max x^2*(1001-x) = 1.5e8
// https://www.wolframalpha.com/input?i=max+x%5E2*%281001-x%29&lang=ja
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
    int n,k;
    cin >> n >> k;
    vector<string> s(n);
    int c1=0;
    for(auto &nx : s){
      cin >> nx;
      for(auto &ny : nx){
        if(ny=='1'){c1++;}
      }
    }
    int van=(n-k+1);
    van*=van;
    if(c1<van){cout << "NO\n";continue;}

    vector<string> res(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        res[i].push_back('1');
      }
    }

    bool ok=true;
    int edge=n-k+1;
    vector<int> sta(edge,0);
    for(int i=0;ok && (i<edge);i++){
      int cur=0;
      for(int j=0;ok && (j<edge);j++){
        cur=max(cur,sta[j]);

        int pot=-1;
        for(int del=cur;del<=n-edge;del++){
          if(s[i+del][j+del]=='0'){continue;}
          if(res[i+del][j+del]=='0'){pot=del;break;}
          res[i+del][j+del]='0';
          van--;
          pot=del;
          break;
        }

        if(pot==-1){ok=false;break;}
        sta[j]=max(sta[j],pot);
        cur=max(cur,pot);
      }
    }

    if(!ok){cout << "NO\n";continue;}
    for(int i=0;van>0 && (i<n);i++){
      for(int j=0;van>0 && (j<n);j++){
        if(s[i][j]=='0'){continue;}
        if(res[i][j]=='0'){continue;}
        res[i][j]='0';
        van--;
      }
    }
    cout << "YES\n";
    for(auto &nx : res){cout << nx << "\n";}
  }
  return 0;
}