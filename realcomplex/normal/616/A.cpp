#include <bits/stdc++.h>

using namespace std;

bool comp(string a,string b){
  if(a.size()<b.size())return true;
  if(b.size()<a.size())return false;
  for(int i = 0;i<(int)a.size();i++){
    if(a[i]<b[i])return true;
    if(a[i]>b[i])return false;
  } 
}

string change(string a){
  string ans;
  for(int i = 0;i<a.size();i++){
    if(a[i]!='0'||i==a.size()-1){
      for(int j = i;j<a.size();j++)ans+=a[j];
      return ans; 
    }
  }
} 

int main(){
  string a,b;
  cin >> a >> b;
  a=change(a);
  b=change(b);
  if(a==b){
    cout << "=";
  }  
  else cout << ((comp(a,b)) ? "<" : ">");
  return 0;
}