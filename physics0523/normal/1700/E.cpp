#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int dx5[5]={1,-1,0,0,0};
int dy5[5]={0,0,1,-1,0};

int n,m;
vector<vector<int>> a;

bool range(int p,int q){
  if(!(0<=p && p<n)){return false;}
  if(!(0<=q && q<m)){return false;}
  return true;
}

int f(int p,int q){
  if(!range(p,q)){return -1;}

  int res=0;
  for(int k=0;k<4;k++){
    int ni=p+dx5[k];
    int nj=q+dy5[k];
    if(!range(ni,nj)){continue;}
    if(a[p][q]>a[ni][nj]){res++;}
  }
  return res;
}

void around(int p,int q,vector<pi> &lis){
  for(int i=0;i<5;i++){
    int ni=p+dx5[i];
    int nj=q+dy5[i];
    if(!range(ni,nj)){continue;}
    lis.push_back({ni,nj});
  }
}

vector<int> bk(5);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  for(int i=0;i<n;i++){
    a[i].resize(m);
    for(int j=0;j<m;j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  vector<vector<pi>> lis(5);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int cnt=f(i,j);
      lis[cnt].push_back({i,j});
    }
  }
  for(int i=0;i<=4;i++){bk[i]=lis[i].size();}
  if(bk[0]==1){
    cout << "0\n";
    return 0;
  }

  pi target;
  for(auto &nx : lis[0]){
    if(a[nx.first][nx.second]!=0){
      target=nx;
      break;
    }
  }
  // cout << target.first << ' ' << target.second << '\n';
  set<long long> rst;
  for(int k=0;k<5;k++){
    int cp=target.first+dx5[k];
    int cq=target.second+dy5[k];
    if(!range(cp,cq)){continue;}

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        vector<pi> lis;
        around(cp,cq,lis);
        around(i,j,lis);
        sort(lis.begin(),lis.end());
        lis.erase(unique(lis.begin(),lis.end()),lis.end());

        int c0=bk[0];
        for(auto &nx : lis){
          if(f(nx.first,nx.second)==0){c0--;}
        }
        swap(a[cp][cq],a[i][j]);
        for(auto &nx : lis){
          if(f(nx.first,nx.second)==0){c0++;}
        }
        if(c0==1){
          long long v1=cp*m+cq;
          long long v2=i*m+j;
          if(v1>v2){swap(v1,v2);}
          rst.insert((v1<<32)+v2);
        }
        swap(a[cp][cq],a[i][j]);
      }
    }
  }

  int rcnt=rst.size();
  if(rcnt==0){cout << "2\n";}
  else{cout << "1 " << rcnt << '\n';}
  return 0;
}