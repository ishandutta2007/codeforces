#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>

using namespace std;

int n;
string s, str;
vector<string>v;

int main(){

  cin>>n;

  for (;getline(cin,s);) str+=s+'\n';

  bool t=0;
  int w=-1;
  for (int i=0; i<(int)str.size(); i++) {
    if (str[i]=='"') {
      if (t) {
	v.push_back(str.substr(w, i-w+1));
	w=-1;
      } else {
	if (w>=0) v.push_back(str.substr(w, i-w));
	w=i;
      }
      t=!t;
    } else if (!t) {
      if (isspace(str[i])) {
	if (w>=0) v.push_back(str.substr(w, i-w));
	w=-1;
      } else if (str[i]=='(' || str[i]==')' || str[i]==',') {
	if (w>=0) v.push_back(str.substr(w, i-w));
	v.push_back(string(1, str[i]));
	w=-1;
      } else if (isalpha(str[i])) {
	if (w<0) w=i;
      }
    }
  }

  
  string c;
  int d, b;
  
  for (int i=0; i<(int)v.size(); i++) {
    if (v[i]=="throw" && v[i+1][0]=='(') c=v[i+2], d=b=0;
    if (c!="") {
      if (v[i]=="try" && v[i+1][0]!=',' && v[i+1][0]!=')') d++;
      if (v[i]=="catch" && v[i+1][0]=='(') {
	if (b==d && v[i+2]==c) {
	  cout<<v[i+4].substr(1, v[i+4].size()-2)<<endl;
	  return 0;
	}
	d--;
	b=min(b, d);
      }
    }      
  }
  cout<<"Unhandled Exception"<<endl;
  return 0;
}