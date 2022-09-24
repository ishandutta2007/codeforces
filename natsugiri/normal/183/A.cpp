#include<string>
#include<iostream>

using namespace std;

long long a, b;
string s;
int main(){
  int n;
  cin>>n;
  a=b=1;
  for(;n--;){
    cin>>s;
    if(s=="UR" || s=="DL")a++;
    if(s=="UL" || s=="DR")b++;
    if(s=="ULDR")a++, b++;
  }
  cout<<a*b<<endl;
  return 0;
}