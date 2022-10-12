#include<bits/stdc++.h>

using namespace std;

bool jud;

void rep(int d,int s,vector<int> &bk){
  if(d==3){
    if(s%10==3){jud=true;}
    return;
  }
  for(int i=0;i<10;i++){
    if(bk[i]>0){
      bk[i]--;
      rep(d+1,s+i,bk);
      bk[i]++;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    jud=false;
    t--;
    int n;
    cin >> n;
    vector<int> bk(10,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      bk[v%10]++;
    }
    rep(0,0,bk);
    if(jud){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}