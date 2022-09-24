#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
  ifstream ifs("input.txt");
  ofstream ofs("output.txt");
  string s;
  int n;
  ifs>>s>>n;
  if((s[0]=='f'&&n==1)||(s[0]=='b'&&n==2))s="L";
  else s="R";
  ofs<<s<<endl;
  return 0;
}