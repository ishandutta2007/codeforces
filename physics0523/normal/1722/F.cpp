#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t>0){
    t--;

    int n,m;
    cin >> n >> m;

    vector<string> s(n),mem;
    for(auto &nx : s){cin >> nx;}
    mem=s;

    bool ok=true;
    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        int cnt=0;
        if(s[i][j]=='*'){cnt++;}
        if(s[i-1][j]=='*'){cnt++;}
        if(s[i][j-1]=='*'){cnt++;}
        if(s[i-1][j-1]=='*'){cnt++;}

        if(cnt!=3){continue;}

        int ni,nj;
        if(s[i][j]=='.'){ni=i+1;nj=j+1;}
        if(s[i-1][j]=='.'){ni=i-2;nj=j+1;}
        if(s[i][j-1]=='.'){ni=i+1;nj=j-2;}
        if(s[i-1][j-1]=='.'){ni=i-2;nj=j-2;}

        for(int di=-2;di<=1;di++){
          for(int dj=-2;dj<=1;dj++){
            int ci=i+di;
            int cj=j+dj;
            if(ci==ni && cj==nj){continue;}
            if(-1<=di && di<=0 && -1<=dj && dj<=0){continue;}
            if(!(0<=ci && ci<n && 0<=cj && cj<m)){continue;}
            if(s[ci][cj]=='*'){ok=false;}
          }
        }

        mem[i][j]='.';
        mem[i-1][j]='.';
        mem[i][j-1]='.';
        mem[i-1][j-1]='.';
      }
    }

    for(auto &nx : mem){
      for(auto &ny : nx){
        if(ny!='.'){ok=false;}
      }
    }

    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }

  return 0;
}