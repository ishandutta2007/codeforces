#include<bits/stdc++.h>

using namespace std;
// .first[0] ... 0
// .first[positive] ... non-zero(sorted)
// .second.first ... remain digits
// .second.second ... leading zero : allowed or not
using pvp=pair<vector<int>,pair<int,int>>;

map<pvp,long long> mp;
long long solve(pvp x){
  if(x.second.first==0){return 1;}
  sort(x.first.begin()+1,x.first.end());
  if(mp.find(x)!=mp.end()){return mp[x];}

  long long cres=0;
  int n=x.first.size();
  int st=0;
  if(x.second.second==0){st=1;}
  for(int i=st;i<n;i++){
    if(x.first[i]>0){
      pvp nx=x;
      nx.first[i]--;
      nx.second.first--;
      nx.second.second=1;
      cres+=solve(nx);
    }
  }
  mp[x]=cres;
  return cres;
}

string let="0123456789abcdef";

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k;
  int t;
  cin >> k >> t;
  vector<int> init_v(16,t);
  for(int len=1;;len++){
    long long cl=solve({init_v,{len,0}});
    if(k>cl){k-=cl;continue;}
    string res;
    vector<int> rem(16,t);
    for(int i=0;i<len;i++){
      int st=0;
      if(i==0){st=1;}
      for(int j=st;j<16;j++){
        if(rem[j]==0){continue;}
        rem[j]--;
        long long subt=solve({rem,{len-i-1,1}});
        if(k>subt){k-=subt;rem[j]++;continue;}
        res.push_back(let[j]);
        break;
      }
    }
    cout << res << '\n';
    return 0;
  }
  return 0;
}