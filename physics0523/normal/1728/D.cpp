#include<bits/stdc++.h>

using namespace std;

string s;
int dp[2048][2048];

void init(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j]=-2;
    }
  }
}

int rep(int l,int r){
  if(l>r){return 0;}
  if(dp[l][r]!=-2){return dp[l][r];}

  for(int i=0;i<2;i++){
    int cur=1e9;
    for(int j=0;j<2;j++){
      int di,dj;
      int nl=l,nr=r;

      if(i==0){di=nl;nl++;}
      else{di=nr;nr--;}
      if(j==0){dj=nl;nl++;}
      else{dj=nr;nr--;}

      int pref=rep(nl,nr);

      if(pref==0){
        if(s[di]<s[dj]){pref=1;}
        if(s[di]>s[dj]){pref=-1;}
      }
      cur=min(pref,cur);
    }
    dp[l][r]=max(dp[l][r],cur);
  }
  return dp[l][r];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> s;
    int l=s.size();
    init(l);
    int res=rep(0,l-1);
    if(res==1){cout << "Alice\n";}
    else if(res==-1){cout << "Bob\n";}
    else{cout << "Draw\n";}
  }
  return 0;
}