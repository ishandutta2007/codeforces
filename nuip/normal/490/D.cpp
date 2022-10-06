#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){
  std::ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  ll p[2][2];
  rep(i,2)
    cin>>p[i][0]>>p[i][1];
  ll p2[2][2],p3[2][2];
  rep(i,2){
    rep(j,2){
      while(p[i][j]%2==0){
        p[i][j]/=2;
        p2[i][j]++;
      }
      while(p[i][j]%3==0){
        p[i][j]/=3;
        p3[i][j]++;
      }
    }
  }
  if(p[0][0]*p[0][1]!=p[1][0]*p[1][1]){
    cout<<-1<<endl;
    return 0;
  }
  ll mint[2][100][100],u,v,INF=1e9;
  pii uv[2][100][100];
  fill(mint[0][0],mint[0][0]+2*10000,INF);
  int du[]={-1,1},dv[]={0,-1};
  rep(i,2){
    u=p2[i][1]+p2[i][0];
    v=p3[i][1]+p3[i][0];
    mint[i][u][v]=0;
    uv[i][u][v]=pii(p2[i][0],p3[i][0]);
    queue<pii> que;
    que.push(pii(u,v));
    while(!que.empty()){
      pii t=que.front();que.pop();
     // cout<<t.X<<","<<t.Y<<":"<<mint[i][t.X][t.Y]<<endl;
      rep(j,2){
        pii tmp=pii(t.X+du[j],t.Y+dv[j]);
        if(tmp.X<0 || tmp.Y<0)continue;
        if(mint[i][tmp.X][tmp.Y]>mint[i][t.X][t.Y]+1){
          mint[i][tmp.X][tmp.Y]=mint[i][t.X][t.Y]+1;
          pii temp=uv[i][t.X][t.Y];
          if(temp.X+du[j]>=0 && temp.Y+dv[j]>=0){
            uv[i][tmp.X][tmp.Y]=pii(temp.X+du[j], temp.Y+dv[j]);
          }else{
            uv[i][tmp.X][tmp.Y]=temp;
          }
          que.push(tmp);
        }
      }
    }
  }
  ll re=INF;
  pii reuv[2][2];
  rep(i,100)
    rep(j,100)
      if(re>mint[0][i][j]+mint[1][i][j]){
        re=mint[0][i][j]+mint[1][i][j];
        rep(k,2){
          reuv[k][0]=uv[k][i][j];
          reuv[k][1]=pii(i-uv[k][i][j].X,j-uv[k][i][j].Y);
        }
      }
  if(re>=INF){
    cout<<-1<<endl;
  }else{
    cout<<re<<endl;
    rep(i,2){
      rep(j,2){
        cout<<p[i][j]*pow(2,reuv[i][j].X)*pow(3,reuv[i][j].Y)<<" ";
//        printf("%I64d ",ll(p[i][j]*pow(2,reuv[i][j].X)*pow(3,reuv[i][j].Y)));
      //  cout<<"("<<p[i][j]<<"*"<<
      //    pow(2,reuv[i][j].X)<<"*"<<pow(3,reuv[i][j].Y)<<")";
      }cout<<endl;
    }
  }
  return 0;
}