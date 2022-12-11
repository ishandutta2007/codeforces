#include <bits/stdc++.h>

using namespace std;

int conf[55][55];
int c1,c2;
int e1,e2;
string ins;

int c(char x){
  return x-48;
}

bool valid(string cf){
  int k1,k2;
  k1=c1,k2=c2;
  for(char x : ins){
    if(cf[c(x)]=='0')k1--;
    else if(cf[c(x)]=='1')k1++;
    else if(cf[c(x)]=='2')k2--;
    else k2++;
    if(k1==e1&&k2==e2)return true;
    if(conf[k1][k2]==-1)return false;
  } 
  return false;
}

void init(){
  for(int i = 0;i<55;i++)
    for(int j = 0;j<55;j++)
      conf[i][j]=-1;
}

int main(){
  init();
  int n,m;
  cin >> n >> m;
  char c;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cin >> c;
      if(c=='.')conf[i][j]=0;
      else if(c=='S')conf[i][j]=0,c1=i,c2=j;
      else if(c=='E')conf[i][j]=0,e1=i,e2=j;
    } 
  } 
  cin >> ins;
  string perm = "0123";
  int ans = valid(perm);
  while(next_permutation(perm.begin(),perm.end())){
    
    if(valid(perm))ans++;
  }
  cout << ans;
  return 0;
}