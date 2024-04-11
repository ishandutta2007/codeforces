#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
set<string>se;
int a[6],ans;
string t="ROYGBV";
string rot(string s){
  int i=0;
  char c=s[0];
  for(i=0;i<s.size()-1;i++)s[i]=s[i+1];
  s[i]=c;
  return s;
}
int re(int i,string s){
  int n,j;
  if(i==6){
    if(se.find(s)==se.end())ans++;
    for(n=0;n<4;n++){
      for(j=0;j<3;j++){
    se.insert(s);
    reverse(s.begin(),s.end());
    se.insert(s);
    reverse(s.begin(),s.end());
    s=rot(s.substr(0,3))+rot(s.substr(3));
      }
      s=s.substr(0,1)+rot(s.substr(1,4))+s.substr(5,1);
    }
    return 0;
  }
  for(n=0;n<6;n++){
    if(a[n]>0){
      a[n]--;
      s[i]=t[n];
      re(i+1,s);
      a[n]++;
    }
  }
  return 0;
}
  
int main(){
  int i,j;
  string s;
  cin>>s;
  ans=0;
  for(i=0;i<6;i++)a[i]=0;
  for(i=0;i<6;i++){
    for(j=0;j<6;j++){
      if(s[i]==t[j])a[j]++;
    }
  }
  re(0,"123456");
  cout<<ans<<endl;
  return 0;
}