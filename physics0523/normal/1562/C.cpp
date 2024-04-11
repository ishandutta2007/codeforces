#include<bits/stdc++.h>

using namespace std;

void out(int a,int b,int c,int d){
  cout << a << ' ';
  cout << b << ' ';
  cout << c << ' ';
  cout << d << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    int tg=-1;
    for(int i=0;i<l;i++){
      if(s[i]=='0'){tg=i;}
    }
    if(tg==-1){out(1,l-1,2,l);}
    else if(tg<(l/2)){
      out(tg+1,l,tg+2,l);
    }
    else{
      out(1,tg+1,1,tg);
    }
  }
  return 0;
}