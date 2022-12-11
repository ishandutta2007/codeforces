#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

int n,a[4444],t[4444],m,ans=0;
vector<int>vec[4444];

void doit(vector<int>a,vector<int>b){
  int sza=a.size(),szb=b.size(),p1=0,p2=0,now=0,res=0;
  a.push_back(1e7); b.push_back(1e7);
  for (;p1<sza||p2<szb;){
    if (p1==sza||b[p2]<a[p1]){
      if (now!=2) ++res, now=2;
      ++p2;
    }else{
      if (now!=1) ++res, now=1;
      ++p1;
    }
  }
  ans=max(ans,res);
}

int main(){
  ios::sync_with_stdio(0);
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i],t[i]=a[i];
  sort(t+1,t+n+1);
  m=unique(t+1,t+n+1)-t-1;
  for (int i=1;i<=n;++i){
    a[i]=lower_bound(t+1,t+m+1,a[i])-t;
    vec[a[i]].push_back(i);
  }
  for (int i=1;i<=m;++i) ans=max(ans,(int)vec[i].size());
  for (int i=1;i<m;++i)
    for (int j=i+1;j<=m;++j)
      doit(vec[i],vec[j]);
  cout<<ans<<endl;
}