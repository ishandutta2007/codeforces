#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<string> s;
vector<vector<int>> id;
char get(int p,int q){
  if(p<0 || n<=p){return '#';}
  if(q<0 || m<=q){return '#';}
  return s[p][q];
}

int fintag(int i,int j){
  if((i+j)%2){return 0;}
  return 3*(i%3)+(j%3);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  s.resize(n);
  id.resize(n);
  for(int i=0;i<n;i++){cin >> s[i];}
  for(int i=0;i<n;i++){
    id[i].resize(m);
    for(int j=0;j<m;j++){
      if(get(i,j)=='#'){continue;}
      if(
        get(i-1,j)=='#' &&
        get(i+1,j)=='#' &&
        get(i,j-1)=='#' &&
        get(i,j+1)=='#'
      ){
        cout << "-1\n";
        return 0;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++){
      if(get(i,j)=='.' && get(i,j+1)=='.'){
        char tag='0'+fintag(i,j)+fintag(i,j+1);
        s[i][j]=tag;
        s[i][j+1]=tag;
      }
    }
  }

  for(int j=0;j<m;j++){
    for(int i=0;i<n-1;i++){
      if(get(i,j)=='.' && get(i+1,j)=='.'){
        char tag='0'+fintag(i,j)+fintag(i+1,j);
        s[i][j]=tag;
        s[i+1][j]=tag;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(get(i,j)!='.'){continue;}
      char tg;
      tg=get(i-1,j);if(tg!='.' && tg!='#'){s[i][j]=tg;}
      tg=get(i+1,j);if(tg!='.' && tg!='#'){s[i][j]=tg;}
      tg=get(i,j-1);if(tg!='.' && tg!='#'){s[i][j]=tg;}
      tg=get(i,j+1);if(tg!='.' && tg!='#'){s[i][j]=tg;}
    }
  }
  for(int i=0;i<n;i++){cout << s[i] << '\n';}
  return 0;
}