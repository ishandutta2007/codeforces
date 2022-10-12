#include<bits/stdc++.h>

using namespace std;

string solve(string s1,string s2){
  int l=s1.size();
  int o1=0,o2=0;
  for(int i=0;i<l;i++){o1+=(s1[i]-'0');}
  for(int i=0;i<l;i++){o2+=(s2[i]-'0');}
  char tg;
  string res;
  if(min(o1,o2)>min(l-o1,l-o2)){tg='1';}
  else{tg='0';}
  s1.push_back('a');
  s2.push_back('b');
  int p1=0,p2=0;
  while(p1<l || p2<l){
    int ns;
    if(p1==l){ns=2;}
    else if(p2==l){ns=1;}
    else if(s1[p1]!=tg){ns=1;}
    else if(s2[p2]!=tg){ns=2;}
    else{ns=1;}
    char ac;
    if(ns==1){
      ac=s1[p1];
      res.push_back(s1[p1]);
    }
    else{
      ac=s2[p2];
      res.push_back(s2[p2]);
    }
    if(ac==s1[p1]){p1++;}
    if(ac==s2[p2]){p2++;}
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
    int n;
    cin >> n;
    string s1,s2,s3,res,cr;
    cin >> s1 >> s2 >> s3;
    res=solve(s1,s2);
    cr=solve(s1,s3);
    if(res.size()>cr.size()){res=cr;}
    cr=solve(s2,s3);
    if(res.size()>cr.size()){res=cr;}
    cout << res << '\n';
  }
  return 0;
}