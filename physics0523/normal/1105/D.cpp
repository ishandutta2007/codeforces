#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long base =2000000000;
long long large=20000000000;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,p;
  cin >> n >> m >> p;
  vector<int> v(p);
  for(auto &nx : v){cin >> nx;}
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}

  priority_queue<pl,vector<pl>,greater<pl>> pq;
  vector<vector<long long>> md(n,vector<long long>(m,8e18));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if('1'<=s[i][j] && s[i][j]<='9'){
        long long val=base*(s[i][j]-'0');
        pq.push({val,i*2000+j});
        md[i][j]=val;
      }
    }
  }

  while(!pq.empty()){
    pl od=pq.top();pq.pop();
    int cx=od.second/2000;
    int cy=od.second%2000;
    int cd=od.first%base;
    int cid=((od.first/base)%10);
    // cout << cx << ' ' << cy << ' ' << cd;
    if(s[cx][cy]!='.' && cid!=(s[cx][cy]-'0')){continue;}
    s[cx][cy]='0'+cid;

    for(int i=0;i<4;i++){
      int nx=cx+dx4[i];
      int ny=cy+dy4[i];
      if(!(0<=nx && nx<n)){continue;}
      if(!(0<=ny && ny<m)){continue;}
      if(s[nx][ny]!='.'){continue;}
      long long nv=od.first+1;
      if(od.first%base==v[cid-1]){
        nv=(od.first/base)*base+large+1;
      }
      // cout << nx << ' ' << ny << ' ' << nv << ' ' << cid << '\n';
      if(md[nx][ny]>nv){
        md[nx][ny]=nv;
        pq.push({nv,nx*2000+ny});
      }
    }
  }

  map<char,int> res;
  for(auto &nx : s){
    for(auto &ny : nx){res[ny]++;}
  }
  for(int i=1;i<=p;i++){
    if(i-1){cout << ' ';}
    cout << res[i+'0'];
  }cout << '\n';
  return 0;
}