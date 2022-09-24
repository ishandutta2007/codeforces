#include<cstdio>
#include<iostream>
#include<string>

using namespace std;


int n;
string s;
int a[256];
int main(){
  scanf("%d", &n);
  cin>>s;
  for (int i=0; i<s.size(); i++) a[s[i]]++;
  s="";
  for (int i='a'; i<='z'; i++) {
    if (a[i]%n!=0) {
      puts("-1");
      return 0;
    }
    s=s+string(a[i]/n, char(i));
  }
  for (int i=0; i<n; i++) cout<<s;
  puts("");
  return 0;
}