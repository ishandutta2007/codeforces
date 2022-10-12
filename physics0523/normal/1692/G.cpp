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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    queue<int> q;
    for(int i=1;i<n;i++){
      if(a[i-1]>=2*a[i]){q.push(i-1);}
    }
    int res=0;
    q.push(1e9);
    for(int i=0;i<n-k;i++){
      while(q.front()<i){q.pop();}
      int bt=i+k;
      if(q.front()>=bt){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}