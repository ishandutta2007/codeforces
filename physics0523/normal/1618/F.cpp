#include<bits/stdc++.h>

using namespace std;

string bi(long long x){
  string res;
  while(x>0){
    res.push_back('0'+(x%2));
    x/=2;
  }
  reverse(res.begin(),res.end());
  return res;
}

void remlz(string &s){
  reverse(s.begin(),s.end());
  while(s[s.size()-1]=='0'){s.pop_back();}
  reverse(s.begin(),s.end());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,y;
  cin >> x >> y;
  if(x==y){cout << "YES\n";return 0;}
  string bx=bi(x),by=bi(y);
  vector<string> s(4);

  s[0]=bx;
  s[0].push_back('0');
  reverse(s[0].begin(),s[0].end());
  remlz(s[0]);
  s[1]=s[0];
  reverse(s[1].begin(),s[1].end());

  s[2]=bx;
  s[2].push_back('1');
  reverse(s[2].begin(),s[2].end());
  s[3]=s[2];
  reverse(s[3].begin(),s[3].end());

  bool ex=false;
  for(int i=0;i<4;i++){
    for(int j=0;j<64;j++){
      int k=by.size()-s[i].size()-j;
      if(k<0){continue;}

      string res;
      for(int l=0;l<j;l++){res.push_back('1');}
      for(auto &nx : s[i]){res.push_back(nx);}
      for(int l=0;l<k;l++){res.push_back('1');}
      if(res==by){ex=true;}
    }
  }
  if(ex){cout << "YES\n";}else{cout << "NO\n";}
  return 0;
}