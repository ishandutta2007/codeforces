#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
  int i,a[26],b[26];
  for(i=0;i<26;i++)a[i]=b[i]=0;
  string s;
  cin>>s;
  for(i=0;i<s.size();i++)a[s[i]-'A']++;
  cin>>s;
  for(i=0;i<s.size();i++)a[s[i]-'A']++;
  cin>>s;
  for(i=0;i<s.size();i++)b[s[i]-'A']++;
  for(i=0;i<26;i++){
    if(a[i]!=b[i]){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}