#include<bits/stdc++.h>

using namespace std;

long long g,x,y,z;

int hit(){
  int r=g;
  g*=x;
  g+=y;
  g%=z;
  return r;
}

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  cin >> g >> x >> y >> z;

  swap(a,b);

  vector<vector<int>> v0(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      v0[i][j]=hit();
    }
  }

  for(int tr=0;tr<2;tr++){
    vector<vector<int>> v1(n);
    for(int i=0;i<n;i++){
      deque<pi> q;
      for(int j=0;j<m;j++){
        while(!q.empty() && (q.front().second<=(j-a))){q.pop_front();}
        while(!q.empty() && (q.back().first >= v0[i][j])){
          q.pop_back();
        }
        q.push_back({v0[i][j],j});

        if((a-1)<=j){
          v1[i].push_back(q.front().first);
        }
      }
    }
    m-=a;m++;

    vector<vector<int>> v2(m,vector<int>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        v2[j][i]=v1[i][j];
      }
    }
    swap(n,m);
    swap(a,b);
    v0=v2;
  }

  long long res=0;
  for(auto &nx : v0){
    for(auto &ny : nx){
      res+=ny;
      // cout << ny << " ";
    }//cout << "\n";
  }
  cout << res << "\n";

  return 0;
}