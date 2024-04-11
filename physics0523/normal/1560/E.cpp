#include<bits/stdc++.h>

using namespace std;

string remc(string s,char c){
  string res;
  for(auto &nx : s){
    if(nx!=c){res.push_back(nx);}
  }
  return res;
}

int f(string &s,string &lis){
  vector<int> ce(26,0);
  for(int i=0;i<lis.size();i++){ce[lis[i]-'a']=i+1;}
  int res=0;
  for(int i=0;i<s.size();i++){
    res+=ce[s[i]-'a'];
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
    string s,lis;
    cin >> s;
    vector<int> bk(26,0);
    for(int i=s.size()-1;i>=0;i--){
      if(bk[s[i]-'a']==0){
        lis.push_back(s[i]);
      }
      bk[s[i]-'a']++;
    }
    reverse(lis.begin(),lis.end());
    int st=1,fi=s.size(),te;
    bool fl=true;
    while(st<=fi){
      te=(st+fi)/2;

      string kh=s.substr(0,te);
      int cf=f(kh,lis);
      if(cf==s.size()){
        string jud=kh,mem=kh;
        for(auto &nx : lis){
          kh=remc(kh,nx);
          jud=jud+kh;
        }
        if(jud==s){
          cout << mem << ' ' << lis << '\n';
          fl=false;
        }
        break;
      }
      if(cf<s.size()){st=te+1;}
      else{fi=te-1;}
    }
    if(fl){cout << "-1\n";}
  }
  return 0;
}