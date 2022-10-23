#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using plp=pair<long long,pl>;

int dx4[4]={1,-1,0,0}; // vert
int dy4[4]={0,0,1,-1}; // horiz

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w;
  cin >> h >> w;
  long long p,q;
  cin >> p >> q;
  vector<string> s(h);
  for(auto &nx : s){cin >> nx;}

  vector<vector<long long>> d(h,vector<long long>(w,4e18));
  {
    priority_queue<plp,vector<plp>,greater<plp>> pq;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if((i+j)%2){continue;}
        if(s[i][j]=='.'){
          d[i][j]=0;
          pq.push({0,{i,j}});
        }
      }
    }

    while(!pq.empty()){
      plp od=pq.top();pq.pop();
      long long cd=od.first;
      long long ci=od.second.first;
      long long cj=od.second.second;
      if(d[ci][cj]<cd){continue;}

      for(int k=0;k<4;k++){
        long long ni=ci+dx4[k];
        long long nj=cj+dy4[k];
        if(!(0<=ni && ni<h)){continue;}
        if(!(0<=nj && nj<w)){continue;}

        if(s[ni][nj]=='#'){continue;}
        if(s[ni][nj]=='.'){continue;}

        long long nd=cd;

        if(s[ni][nj]=='L'){
          if(k<=1){nd+=p;}
          else{nd+=q;}
          nj++;
        }
        else if(s[ni][nj]=='R'){
          if(k<=1){nd+=p;}
          else{nd+=q;}
          nj--;
        }
        else if(s[ni][nj]=='U'){
          if(k<=1){nd+=q;}
          else{nd+=p;}
          ni++;
        }
        else if(s[ni][nj]=='D'){
          if(k<=1){nd+=q;}
          else{nd+=p;}
          ni--;
        }

        if(d[ni][nj]>nd){
          d[ni][nj]=nd;
          pq.push({nd,{ni,nj}});
        }
      }
    }
  }

  vector<vector<long long>> d2(h,vector<long long>(w,4e18));
  {
    priority_queue<plp,vector<plp>,greater<plp>> pq;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if((i+j)%2==0){continue;}
        if(s[i][j]=='.'){
          d2[i][j]=0;
          pq.push({0,{i,j}});
        }
      }
    }

    while(!pq.empty()){
      plp od=pq.top();pq.pop();
      long long cd=od.first;
      long long ci=od.second.first;
      long long cj=od.second.second;
      if(d2[ci][cj]<cd){continue;}

      for(int k=0;k<4;k++){
        long long ni=ci+dx4[k];
        long long nj=cj+dy4[k];
        if(!(0<=ni && ni<h)){continue;}
        if(!(0<=nj && nj<w)){continue;}

        if(s[ni][nj]=='#'){continue;}
        if(s[ni][nj]=='.'){continue;}

        long long nd=cd;

        if(s[ni][nj]=='L'){
          if(k<=1){nd+=p;}
          else{nd+=q;}
          nj++;
        }
        else if(s[ni][nj]=='R'){
          if(k<=1){nd+=p;}
          else{nd+=q;}
          nj--;
        }
        else if(s[ni][nj]=='U'){
          if(k<=1){nd+=q;}
          else{nd+=p;}
          ni++;
        }
        else if(s[ni][nj]=='D'){
          if(k<=1){nd+=q;}
          else{nd+=p;}
          ni--;
        }

        if(d2[ni][nj]>nd){
          d2[ni][nj]=nd;
          pq.push({nd,{ni,nj}});
        }
      }
    }
  }

  long long res=4e18;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      // cerr << d[i][j] << "," << d2[i][j] << " ";
      for(int k=0;k<4;k++){
        int ni=i+dx4[k];
        int nj=j+dy4[k];
        if(!(0<=ni && ni<h)){continue;}
        if(!(0<=nj && nj<w)){continue;}
        res=min(res,d[i][j]+d2[ni][nj]);
        res=min(res,d2[i][j]+d[ni][nj]);
      }
    }// cerr << "\n";
  }

  if(res>1e18){res=-1;}
  cout << res << "\n";
  return 0;
}