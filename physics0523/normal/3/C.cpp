#include<bits/stdc++.h>

using namespace std;

int id(vector<string> &s){
  int res=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      res*=3;
      if(s[i][j]=='X'){res++;}
      if(s[i][j]=='0'){res+=2;}
    }
  }
  return res;
}

int typ(char c){
  if(c=='X'){return 1;}
  if(c=='0'){return 2;}
  return 0;
}

int jud(vector<string> &s){
  for(int i=0;i<3;i++){
    if(s[i][0]==s[i][1] && s[i][1]==s[i][2] && typ(s[i][0])>0){
      return typ(s[i][0]);
    }
  }
  for(int i=0;i<3;i++){
    if(s[0][i]==s[1][i] && s[1][i]==s[2][i] && typ(s[0][i])>0){
      return typ(s[0][i]);
    }
  }

  if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && typ(s[0][0])>0){
    return typ(s[0][0]);
  }
  if(s[0][2]==s[1][1] && s[1][1]==s[2][0] && typ(s[0][2])>0){
    return typ(s[0][2]);
  }

  int tur=0,fil=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(s[i][j]=='X'){tur++;fil++;}
      if(s[i][j]=='0'){tur--;fil++;}
    }
  }
  if(fil==9){return 3;}

  if(tur==0){return -1;}
  return -2;
}

map<int,int> res;

void rep(vector<string> &s){
  int jv=jud(s);
  res[id(s)]=jv;
  if(jv>0){return;}
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(s[i][j]=='.'){
        if(jv==-1){s[i][j]='X';}
        else{s[i][j]='0';}
        rep(s);
        s[i][j]='.';
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> init={"...","...","..."};
  rep(init);

  vector<string> s(3);
  for(auto &nx : s){cin >> nx;}
  int jv=res[id(s)];
  if(jv==-1){cout << "first\n";}
  else if(jv==-2){cout << "second\n";}
  else if(jv==0){cout << "illegal\n";}
  else if(jv==1){cout << "the first player won\n";}
  else if(jv==2){cout << "the second player won\n";}
  else{cout << "draw\n";}
  return 0;
}