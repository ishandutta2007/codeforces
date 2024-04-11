#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;


int main(){
  string s;
  cin>>s;
  int p;
  for (;;) {
    p=s.find("WUB");
    if (p==s.npos) break;
    s.replace(p, 3, " ");
  }
  stringstream ss(s);
  p=0;
  for (;ss>>s; p++) {
    if (p) cout<<' ';
    cout<<s;
  }
  cout<<endl;
  return 0;
}