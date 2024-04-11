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
    map<int,vector<int>> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    int x=a[0],l=1,r=1,sc=1;
    for(auto &nx : mp){
      vector<int> cv=nx.second;
      int sz=cv.size();
      int lh=1e9,cl=-1;
      for(int i=0;i<sz;i++){
        if(lh>-cv[i]+2*i){
          lh=(-cv[i]+2*i);
          cl=cv[i];
        }
        int eh=(-cv[i]+2*i)+1;
        if(sc<eh-lh){
          sc=eh-lh;
          l=cl+1;r=cv[i]+1;x=nx.first;
        }
      }
    }
    cout << x << ' ' << l << ' ' << r << '\n';
  }
  return 0;
}