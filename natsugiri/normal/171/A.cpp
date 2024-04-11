#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;
int main(){
  int n,m;
  string s;

  cin>>n>>s;
  reverse(s.begin(),s.end());
  stringstream ss(s);
  ss>>m;
  cout<<n+m<<endl;
  return 0;
}