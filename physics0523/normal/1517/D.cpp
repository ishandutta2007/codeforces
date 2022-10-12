#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w,k;
  cin >> h >> w >> k;
  vector<vector<int>> he(h,vector<int>(w-1));
  vector<vector<int>> ve(h-1,vector<int>(w));
  vector<pi> eg;

  for(int i=0;i<h;i++){
    for(int j=0;j<(w-1);j++){
      cin >> he[i][j];
      eg.push_back(make_pair(he[i][j],i*w+j));
    }
  }
  for(int i=0;i<(h-1);i++){
    for(int j=0;j<w;j++){
      cin >> ve[i][j];
      eg.push_back(make_pair(ve[i][j],h*w+i*w+j));
    }
  }
  sort(eg.begin(),eg.end());

  if(k%2){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(j){cout << ' ';}
        cout << "-1";
      }
      cout << '\n';
    }
    return 0;
  }

  vector<int> dp(12*h*w,inf);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      dp[i*w+j]=0;
    }
  }
  for(int i=1;i<12;i++){
    for(auto &nx : eg){
      int c1i,c1j,c2i,c2j;
      int eid=nx.second;
      int etg=(nx.second%(h*w));
      int ec=nx.first;
      //cout << eid << ' ' << etg << ' ' << ec << '\n';
      c1i=etg/w;
      c1j=etg%w;
      if(eid/(h*w)){//ve
        c2i=c1i;c2j=c1j;
        c2i++;
      }
      else{//he
        c2i=c1i;c2j=c1j;
        c2j++;
      }
      dp[i*h*w+c1i*w+c1j]=min(dp[(i-1)*h*w+c2i*w+c2j]+ec,dp[i*h*w+c1i*w+c1j]);
      dp[i*h*w+c2i*w+c2j]=min(dp[(i-1)*h*w+c1i*w+c1j]+ec,dp[i*h*w+c2i*w+c2j]);
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(j){cout << ' ';}
      cout << 2*dp[(k/2)*h*w+i*w+j];
    }cout << '\n';
  }
  return 0;
}