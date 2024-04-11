#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> jp(n+1);
  for(int i=0;i<=n;i++){jp[i]=i;}
  for(int i=0;i<m;i++){
    int v;
    cin >> v;
    jp[v]=-1;
  }
  for(int i=1;i<=n;i++){
    if(jp[i]==-1){jp[i]=jp[i-1];}
  }
  if(jp[0]==-1){cout << "-1\n";return 0;}
  long long res=8e18;
  for(int i=1;i<=k;i++){
    long long w;
    cin >> w;
    long long cnt=0;
    int tg=0;
    while(tg<n){
      int ntg=jp[min(n,tg+i)];
      if(tg==ntg){cnt=-1;break;}
      cnt++;
      tg=ntg;
    }
    if(cnt>0){res=min(res,cnt*w);}
  }
  if(res>6e18){res=-1;}
  cout << res << '\n';
  return 0;
}