#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  vector<int> lf(n+2,0),rg(n+2,0);
  int mem;
  mem=0;
  for(int i=1;i<=n;i++){
    if(mem>=0){if(s[i-1]=='('){mem++;}else{mem--;}}
    if(mem<0){mem=-1;}
    lf[i]=mem;
    //cout << lf[i] << ' ';
  }//cout << '\n';
  mem=0;
  for(int i=n;i>=1;i--){
    if(mem>=0){if(s[i-1]==')'){mem++;}else{mem--;}}
    if(mem<0){mem=-1;}
    rg[i]=mem;
    //cout << rg[i] << ' ';
  }//cout << '\n';
  int res=0;
  for(int i=1;i<=n;i++){
    if(lf[i-1]<0 || rg[i+1]<0){continue;}
    //cout << lf[i-1] << ' ' << rg[i+1] << '\n';
    if(s[i-1]=='('){
      if(lf[i-1]-1==rg[i+1]){res++;}
    }
    else{
      if(lf[i-1]+1==rg[i+1]){res++;}
    }
  }
  cout << res << '\n';
  return 0;
}