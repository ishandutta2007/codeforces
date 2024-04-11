#include<bits/stdc++.h>

using namespace std;
using pci=pair<char,int>;

void comp(vector<pci> &cur){
  vector<pci> res;
  res.push_back(cur[0]);
  for(int i=1;i<cur.size();i++){
    if(res.back().first==cur[i].first){
      res[res.size()-1].second+=cur[i].second;
    }
    else{
      res.push_back(cur[i]);
    }
  }
  cur=res;
}

void erase_0(vector<pci> &cur){
  vector<pci> res;
  for(auto &nx : cur){
    if(nx.second==0){continue;}
    res.push_back(nx);
  }
  cur=res;
}

int f(vector<pci> &cur){
  int opn=1e9;
  int sz=cur.size();
  for(int i=0;i<sz;i++){
    if(i==0 || i==(sz-1)){
      opn=min(opn,cur[i].second);
    }
    else{
      opn=min(opn,(cur[i].second+1)/2);
    }
  }
  for(int i=0;i<sz;i++){
    if(i==0 || i==(sz-1)){
      cur[i].second-=opn;
    }
    else{
      cur[i].second-=2*opn;
    }
    cur[i].second=max(0,cur[i].second);
  }
  return opn;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;

  vector<pci> cv;
  int cnt=1;
  for(int i=1;i<s.size();i++){
    if(s[i-1]==s[i]){cnt++;}
    else{
      cv.push_back({s[i-1],cnt});
      cnt=1;
    }
  }
  cv.push_back({s[s.size()-1],cnt});

  int res=0;
  while(cv.size()>1){
    res+=f(cv);
    erase_0(cv);
    comp(cv);
    // for(auto &nx: cv){
    //   cerr << nx.first << " " << nx.second << "\n";
    // }cerr << "\n";
  }
  cout << res << "\n";
  return 0;
}