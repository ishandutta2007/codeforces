#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n+1),q;
  for(int i=1;i<=n;i++){cin >> p[i];}
  q=p;
  vector<int> fl(n+1,1e9);
  for(int i=1;i<=n;i++){
    if(fl[i]<i){continue;}
    int v=i;
    while(1){
      fl[v]=i;
      if(fl[p[v]]<=i){
        if(fl[p[v]]==i){q[v]=-1;}
        break;
      }
      v=p[v];
    }
  }
  int tg=-1;
  for(int i=1;i<=n;i++){
    if(q[i]==-1 && p[i]==i){tg=i;break;}
  }
  for(int i=1;i<=n;i++){
    if(q[i]==-1){
      if(tg==-1){tg=i;}
      q[i]=tg;
    }
  }
  int res=0;
  for(int i=1;i<=n;i++){
    if(p[i]!=q[i]){res++;}
  }
  cout << res << '\n';
  for(int i=1;i<=n;i++){
    if(i-1){cout << ' ';}
    cout << q[i];
  }cout << '\n';
  return 0;
}