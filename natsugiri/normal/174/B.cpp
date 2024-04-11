#include<cstdio>
#include<vector>
#include<string>
#include<iostream>

using namespace std;


int n;
string s;
vector<string>v;
int main(){
  cin>>s;
  int l,r;

  for(l=0;l<(int)s.size() && s[l]!='.';l++);
  if(l==0 || l>8 || l==(int)s.size()){puts("NO");return 0;}
  v.push_back(s.substr(0,l));
  
  for(r=++l;r<s.size();r++){
    if(s[r]=='.'){
      if(r-l>11 || r-l<2){puts("NO");return 0;}
      else if(r-l>3){
	v.push_back(s.substr(l,3));
	v.push_back(s.substr(l+3,r-l-3));
      }else{
	v.push_back(s.substr(l,1));
	v.push_back(s.substr(l+1,r-l-1));
      }
      l=r+1;
    }
  }
  if(r-l>3 || r-l<1){puts("NO");return 0;}
  v.push_back(s.substr(l));
  puts("YES");
  for(int i=0;i<(int)v.size();i+=2)
    cout<<v[i]<<'.'<<v[i+1]<<endl;
    
  return 0;
}