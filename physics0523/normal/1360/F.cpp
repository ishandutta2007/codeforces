#include<bits/stdc++.h>

using namespace std;

set<string> listup(string &s){
  set<string> st;
  string cur=s;
  for(int i=0;i<s.size();i++){
    for(char c='a';c<='z';c++){
      cur[i]=c;
      st.insert(cur);
    }
    cur[i]=s[i];
  }
  return st;
}

int dist(string &s,string &t){
  int res=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!=t[i]){res++;}
  }
  return res;
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
    for(auto &nx : s){cin >> nx;}
    set<string> st=listup(s[0]);
    for(int i=1;i<n;i++){
      set<string> nst;
      for(auto &nx : st){
        string curs=nx;
        if(dist(curs,s[i])<=1){nst.insert(curs);}
      }
      st.swap(nst);
    }
    if(st.empty()){cout << "-1\n";}
    else{cout << (*st.begin()) << '\n';}
  }
  return 0;
}