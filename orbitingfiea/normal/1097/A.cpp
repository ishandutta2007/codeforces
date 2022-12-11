#include<bits/stdc++.h>
using namespace std;

string s, t;

int main(){
  cin>>s;
  for (int i=1;i<=5;++i){
    cin>>t;
    if (s[0]==t[0]||s[1]==t[1]){
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}