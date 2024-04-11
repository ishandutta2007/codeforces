#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct SKILL_T{
  string s;
  int e;
};
bool operator<(SKILL_T a,SKILL_T b){
  return a.s<b.s;
}

int main(){
  int n,m,i,t,f;
  double k;
  string str;
  vector<SKILL_T>v;
  SKILL_T sk;
  cin>>n>>m>>k;
  for(i=0;i<n;i++){
    cin>>str>>t;
    sk.s=str;
    sk.e=(int)(t*k+0.000001);
    if(sk.e<100)sk.e=-1;
    v.push_back(sk);
  }
  for(i=0;i<m;i++){
    cin>>str;
    f=0;
    for(t=0;t<v.size();t++){
      if(v[t].s==str){
	f=1;
	if(v[t].e==-1)v[t].e=0;
      }
    }
    if(f==0){
      sk.s=str;
      sk.e=0;
      v.push_back(sk);
    }
  }
  sort(v.begin(),v.end());
  for(i=t=0;i<v.size();i++){
    if(v[i].e>-1)t++;
  }
  cout<<t<<endl;
  for(i=0;i<v.size();i++){
    if(v[i].e>-1)cout<<v[i].s<<" "<<v[i].e<<endl;
  }
  return 0;
}