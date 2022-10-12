#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++){cin >> p[i];}
  vector<int> d(n-1);
  for(int i=0;i<n-1;i++){
    if(p[i]<p[i+1]){d[i]=1;}
    else{d[i]=0;}
  }
  int cl=1,mal=-1;
  for(int i=1;i<=n-1;i++){
    if(i==(n-1) || d[i-1]!=d[i]){
      mal=max(cl,mal);
      cl=1;
    }
    else{cl++;}
  }
  if(mal%2==1){cout << "0\n";return 0;}

  vector<int> up,dw;
  cl=1;
  for(int i=1;i<=n-1;i++){
    if(i==(n-1) || d[i-1]!=d[i]){
      if(cl==mal){
        if(d[i-1]==1){up.push_back(i-1);}
        else{dw.push_back(i-cl);}
      }
      cl=1;
    }
    else{cl++;}
  }
  if(up.size()!=1 || dw.size()!=1){cout << "0\n";return 0;}
  if(up[0]+1!=dw[0]){cout << "0\n";return 0;}
  cout << "1\n";
  return 0;
}