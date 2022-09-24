#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>v;
string s,t;


int main(){
  int n,i;
  cin>>n;
  for(;n--;){
    cin>>s;
    if(s=="pwd"){
      for(i=0;i<(int)v.size();i++)cout<<'/'<<v[i];
      cout<<'/'<<endl;
    }else{
      cin>>s;
      i=0;
      if(s[0]=='/'){v.clear();i=1;}
      for(;i<(int)s.size();i++){
	t="";
	for(;s[i]!='/'&&i<(int)s.size();i++)t+=s[i];
	if(t=="..")v.pop_back();
	else v.push_back(t);
      }
    }
  }
  return 0;
}