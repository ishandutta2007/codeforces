#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<string> vs;
char access(int p,int q){
  if(p<0 || n<=p){return '.';}
  if(q<0 || m<=q){return '.';}
  return vs[p][q];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n >> m;
    vs.clear();
    vs.resize(n);
    int key;
    if(n%3==0){key=1;}else{key=0;}
    for(int i=0;i<n;i++){
      cin >> vs[i];
      if(i%3==key){
        for(int j=0;j<m;j++){vs[i][j]='X';}
      }
    }
    for(int i=key+3;i<n;i+=3){
      for(int j=0;j<m;j++){
        if(access(i-2,j-1)=='.' && access(i-1,j-1)=='.' && access(i-2,j+1)=='.' && access(i-1,j+1)=='.'){
          vs[i-2][j]='X';vs[i-1][j]='X';
          break;
        }
      }
    }
    for(int i=0;i<n;i++){cout << vs[i] << '\n';}
  }
  return 0;
}