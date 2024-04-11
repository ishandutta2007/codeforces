#include<bits/stdc++.h>

using namespace std;

vector<string> s;

vector<int> rep(int pt,int st,int fi){
  vector<int> res;
  if(s[st].size()==pt){st++;res.push_back(0);}
  if(st<=fi){
    int cst=st;
    for(int i=st+1;i<=fi+1;i++){
      if(i==fi+1 || s[cst][pt]!=s[i][pt]){
        vector<int> cres=rep(pt+1,cst,i-1);
        for(auto &nx : cres){nx++;}
        res.insert(res.end(),cres.begin(),cres.end());
        cst=i;
      }
    }
  }
  if(res[0]!=0){
    int tg=0;
    for(int i=0;i<res.size();i++){
      if(res[i]>res[tg]){tg=i;}
    }
    res[tg]=0;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  s.resize(n);
  for(int i=0;i<n;i++){cin >> s[i];}
  s.push_back("");
  sort(s.begin(),s.end());
  vector<int> res=rep(0,0,n);
  int sig=0;
  for(auto &nx : res){sig+=nx;}
  cout << sig << '\n';
  return 0;
}