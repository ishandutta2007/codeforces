// #pragma GCC target("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define MXM 2000002

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<pair<int,int>>> pfact(MXM);
  for(int i=2;i<MXM;i++){
    if(pfact[i].size()!=0){continue;}
    for(int j=i;j<MXM;j+=i){
      int cur=j,cc=0;
      while(cur%i==0){
        cc++;
        cur/=i;
      }
      pfact[j].push_back({i,cc});
    }
  }
  // for(int i=2;i<30;i++){
  //   cerr << i << " : ";
  //   for(auto &nx : pfact[i]){
  //     cerr << nx.first << ',' << nx.second << ' ';
  //   }
  //   cerr << '\n';
  // }
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());

  vector<int> cnt(MXM,0);
  vector<vector<int>> mem(MXM);
  for(int i=0;i<n;i++){
    int nx=a[i];
    if(cnt[nx]==0){
      cnt[nx]=1;
      mem[nx].push_back(i);
    }
    else{
      nx--;
      for(auto &pf : pfact[nx]){
        if(pf.second>cnt[pf.first]){mem[pf.first].clear();}
        if(pf.second>=cnt[pf.first]){mem[pf.first].push_back(i);}
        cnt[pf.first]=max(cnt[pf.first],pf.second);
      }
    }
  }
  bool omake=false;
  vector<bool> pain(n,false);
  for(auto &nx : mem){
    if(nx.size()==1){
      pain[nx[0]]=true;
    }
  }
  for(int i=0;i<n;i++){
    if(!pain[i]){omake=true;}
  }

  long long res=1;
  for(int i=2;i<MXM;i++){
    res*=power(i,cnt[i]);res%=mod;
  }
  if(omake){res++;res%=mod;}
  cout << res << '\n';
  return 0;
}