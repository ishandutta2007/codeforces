#include<bits/stdc++.h>

using namespace std;

bool isvalid(vector<int> &a){
  for(int i=0;i<10;i++){
    if(a[i]<0){return false;}
  }
  return true;
}

int sig(vector<int> &a){
  int res=0;
  for(int i=0;i<10;i++){res+=a[i];}
  return res;
}

string s,t;
vector<int> dg(16);
string restore(int d){
  vector<int> cdg=dg;
  int sd=d;
  while(d>0){cdg[d%10]--;d/=10;}
  if(!isvalid(cdg)){return "-";}
  if(sd!=sig(cdg)){return "-";}
  for(int i=0;i<t.size();i++){cdg[t[i]-'0']--;}
  if(!isvalid(cdg)){return "-";}
  if(t[0]=='0' && sig(cdg)==cdg[0]){return "-";}
  int tins=t[0]-'0';
  for(int i=1;i<t.size();i++){
    if(t[i-1]<t[i]){tins++;break;}
    if(t[i-1]>t[i]){break;}
  }
  string res,resl;
  resl=t;
  for(int i=0;i<10;i++){
    for(int j=0;j<cdg[i];j++){resl.push_back('0'+i);}
  }
  if(resl[0]=='0'){resl="@";}
  int cs=sig(cdg),i=0;
  while(cs>0){
    int tg=100;
    for(int j=0;j<10;j++){
      if(i==0 && j==0){continue;}
      if(cdg[j]>0){tg=j;break;}
    }
    //cout << res << ' ' << tg << ' ' << tins << '\n';
    if(i==1 && tins<=tg){
      tins=1000;
      res=res+t;i=1;
      continue;
    }
    if(tg==100){res="@";break;}
    res.push_back(tg+'0');i=1;
    cdg[tg]--;cs--;
  }
  if(tins!=1000){res=res+t;}
  return min(res,resl);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> t;
  if(s=="10" && t=="0"){cout << "0\n";return 0;}
  if(s=="01" && t=="0"){cout << "0\n";return 0;}
  for(int i=0;i<s.size();i++){dg[s[i]-'0']++;}
  for(int i=max(1,(int)s.size()-10);i<s.size();i++){
    string res=restore(i);
    //cout << res << '\n';
    if(res!="-"){cout << res << '\n';return 0;}
  }
  return 0;
}