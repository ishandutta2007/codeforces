#include<bits/stdc++.h>

using namespace std;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(int i=0;i<n;i++){cin >> s[i];}
  int sp,sq,tp,tq;
  cin >> sp >> sq >> tp >> tq;
  sp--;sq--;tp--;tq--;
  if(sp==tp && sq==tq){
    for(int k=0;k<4;k++){
      int np=sp+dx4[k],nq=sq+dy4[k];
      if(np<0 || n<=np){continue;}
      if(nq<0 || m<=nq){continue;}
      if(s[np][nq]=='.'){cout << "YES\n";return 0;}
    }
    cout << "NO\n";
    return 0;
  }
  if(s[tp][tq]=='X'){
    s[tp][tq]='.';
    vector<bool> fl(n*m,false);
    queue<int> qu;
    fl[sp*m+sq]=true;
    qu.push(sp*m+sq);
    while(!qu.empty()){
      int od=qu.front();qu.pop();
      int p=od/m,q=od%m;
      for(int k=0;k<4;k++){
        int np=p+dx4[k],nq=q+dy4[k];
        if(np<0 || n<=np){continue;}
        if(nq<0 || m<=nq){continue;}
        if(fl[np*m+nq]){continue;}
        if(s[np][nq]=='X'){continue;}
        fl[np*m+nq]=true;
        qu.push(np*m+nq);
      }
    }
    if(fl[tp*m+tq]){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  else{
    vector<pair<int,int>> vp;
    for(int k=0;k<4;k++){
      int np=tp+dx4[k],nq=tq+dy4[k];
      if(np<0 || n<=np){continue;}
      if(nq<0 || m<=nq){continue;}
      if(s[np][nq]=='.'){vp.push_back(make_pair(np,nq));}
    }
    for(auto &cf : vp){
      //cout << cf.first << ' ' << cf.second << '\n';
      s[cf.first][cf.second]='X';

      vector<bool> fl(n*m,false);
      queue<int> qu;
      fl[sp*m+sq]=true;
      qu.push(sp*m+sq);
      while(!qu.empty()){
        int od=qu.front();qu.pop();
        int p=od/m,q=od%m;
        for(int k=0;k<4;k++){
          int np=p+dx4[k],nq=q+dy4[k];
          if(np<0 || n<=np){continue;}
          if(nq<0 || m<=nq){continue;}
          if(fl[np*m+nq]){continue;}
          if(s[np][nq]=='X'){continue;}
          fl[np*m+nq]=true;
          qu.push(np*m+nq);
        }
      }
      if(fl[tp*m+tq]){cout << "YES\n";return 0;}

      s[cf.first][cf.second]='.';
    }
    cout << "NO\n";
  }
  return 0;
}