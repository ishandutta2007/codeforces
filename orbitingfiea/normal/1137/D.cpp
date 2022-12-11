#include<bits/stdc++.h>
#define ll long long
using namespace std;

void out(int s){
  cout<<"next";
  for (int i=0;i<10;++i)
    if (s>>i&1) cout<<' '<<i;
  cout<<endl;
  cout.flush();
}
bool sam(int s){
  int fl=0, T;
  cin>>T;
  while (T--){
    string str; cin>>str;
    int t=0;
    for (auto c:str)
      t|=1<<(c-'0');
    if ((s&t)==s) fl=1;
  }
  return fl;
}

int main(){
  int a=1, b=2, c=1020;
  while (1){
    out(a);
    sam(0);
    out(a+b);
    if (sam(a+b)) break;
  }
  while (1){
    out(a+b+c);
    if (sam(a+b+c)) break;
  }
  cout<<"done"<<endl;
  cout.flush();
}