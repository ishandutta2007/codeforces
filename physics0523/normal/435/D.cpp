#include<bits/stdc++.h>

using namespace std;

void rot90(int &n,int &m,vector<string> &s){
  vector<string> res(m);
  for(int i=m-1;i>=0;i--){
    for(int j=0;j<n;j++){
      res[m-1-i].push_back(s[j][i]);
    }
  }
  swap(n,m);
  s=res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}

  int res=0;
  for(int rt=0;rt<4;rt++){
    vector<vector<int>> rw(n,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        rw[i][j+1]=rw[i][j];
        if(s[i][j]=='1'){rw[i][j+1]++;}
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        for(int e=0;e<=i;e++){
          int x=i-e;
          int l=j-e;
          int r=j+e;
          if(!(0<=l && l<=(m-1))){break;}
          if(!(0<=r && r<=(m-1))){break;}
          if(s[x][l]=='1'){break;}
          if(s[x][r]=='1'){break;}
          if(e>0 && rw[x][l]==rw[x][r+1]){res++;}
        }
        for(int e=0;e<=i;e++){
          int x=i-e;
          int l=j;
          int r=j+e;
          if(!(0<=l && l<=(m-1))){break;}
          if(!(0<=r && r<=(m-1))){break;}
          if(s[x][l]=='1'){break;}
          if(s[x][r]=='1'){break;}
          if(e>0 && rw[x][l]==rw[x][r+1]){res++;}
        }
      }
    }
    rot90(n,m,s);
  }
  cout << res << "\n";
  return 0;
}