#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

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

int lev(vector<int> &v){
  if(v[0]==0&&v[1]==0){return 2;}
  else if(v[0]==0||v[1]==0){return 1;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin >> n >> m >> q;
  vector<long long> res(q,0);
  vector<long long> x(q),y(q),t(q);
  for(int i=0;i<q;i++){
    cin >> x[i] >> y[i] >> t[i];
    x[i]--;y[i]--;t[i]++;
  }

  map<pair<int,int>,int> mp;
  int p1=0,p2=0,pv;
  for(int i=0;i<q;i++){
    pv=mp[{x[i],y[i]}];
    if(pv>0){
      if(pv%2==(x[i]+y[i])%2){p1--;}
      else{p2--;}
    }
    mp[{x[i],y[i]}]=t[i];
    pv=mp[{x[i],y[i]}];
    if(pv>0){
      if(pv%2==(x[i]+y[i])%2){p1++;}
      else{p2++;}
    }
    if(p1==0){res[i]+=(mod-1);res[i]%=mod;}
    if(p2==0){res[i]+=(mod-1);res[i]%=mod;}
  }
  mp.clear();

  int fr=n,sr=m;
  int fe=0,se=0;
  vector<vector<int>> fc(n,vector<int>(2,0));
  vector<vector<int>> sc(m,vector<int>(2,0));
  int fl,sl;
  for(int i=0;i<q;i++){
    fl=lev(fc[x[i]]);
    sl=lev(sc[y[i]]);
    if(fl==2){fr--;}if(sl==2){sr--;}
    if(fl==0){fe--;}if(sl==0){se--;}

    pv=mp[{x[i],y[i]}];
    if(pv>0){
      if(y[i]%2==pv%2){fc[x[i]][0]--;}else{fc[x[i]][1]--;}
      if(x[i]%2==pv%2){sc[y[i]][0]--;}else{sc[y[i]][1]--;}
    }
    mp[{x[i],y[i]}]=t[i];
    pv=mp[{x[i],y[i]}];
    if(pv>0){
      if(y[i]%2==pv%2){fc[x[i]][0]++;}else{fc[x[i]][1]++;}
      if(x[i]%2==pv%2){sc[y[i]][0]++;}else{sc[y[i]][1]++;}
    }

    fl=lev(fc[x[i]]);
    sl=lev(sc[y[i]]);
    if(fl==2){fr++;}if(sl==2){sr++;}
    if(fl==0){fe++;}if(sl==0){se++;}
    if(fe==0){res[i]+=power(2,fr);res[i]%=mod;}
    if(se==0){res[i]+=power(2,sr);res[i]%=mod;}
  }

  for(int i=0;i<q;i++){cout << res[i] << '\n';}
  return 0;
}