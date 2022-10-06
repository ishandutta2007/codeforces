#include<bits/stdc++.h>

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

typedef pair<int,int> pii;
typedef long long ll;

string nxt(string str,int t){
  int n=str.size();
  return str.substr(n-t)+str.substr(0,n-t);
}

int main(){
  string str;
  cin>>str;
  int l,r,t,q;
  cin>>q;
  while(q--){
    cin>>l>>r>>t; --l;
    t%=r-l;
    str=str.substr(0,l)+nxt(str.substr(l,r-l),t)+str.substr(r);
  }
  cout<<str<<endl;
  return 0;
}