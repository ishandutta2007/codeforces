#include<bits/stdc++.h>
#define mod 1000000007

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

long long height(long long x){
  long long res=0;
  while(x>0){res++;x/=2;}
  return res;
}

long long cvrt(string &s){
  if(s[0]=='w'){return 1;}
  if(s[0]=='y'){return 2;}
  if(s[0]=='g'){return 3;}
  if(s[0]=='b'){return 4;}
  if(s[0]=='r'){return 5;}
  if(s[0]=='o'){return 6;}
  return -1;
}

vector<long long> merge(vector<long long> &l,vector<long long> &r){
  vector<long long> res(6,0);
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      long long del=(l[i]*r[j])%mod;
      if(i!=0&&i!=1&&j!=0&&j!=1){
        res[0]+=del;res[0]%=mod;
        res[1]+=del;res[1]%=mod;
      }
      if(i!=2&&i!=3&&j!=2&&j!=3){
        res[2]+=del;res[2]%=mod;
        res[3]+=del;res[3]%=mod;
      }
      if(i!=4&&i!=5&&j!=4&&j!=5){
        res[4]+=del;res[4]%=mod;
        res[5]+=del;res[5]%=mod;
      }
    }
  }
  return res;
}

vector<long long> gen(long long h){
  long long val=power(4,(1ll<<h)-2);
  vector<long long> res(6,val);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k;
  cin >> k;
  int n;
  cin >> n;
  map<long long,long long> mp;
  set<long long> st;
  for(int i=0;i<n;i++){
    long long v;
    string s;
    cin >> v >> s;
    mp[v]=cvrt(s);
    while(v>=1){st.insert(v);v/=2;}
  }
  map<long long,vector<long long>> dp;
  vector<long long> vv;
  for(auto &nx : st){vv.push_back(nx);}
  reverse(vv.begin(),vv.end());
  for(auto &nx : vv){
    if(height(nx)==k){
      dp[nx].resize(6);
      long long col=mp[nx];
      if(col==0){
        for(int i=0;i<6;i++){dp[nx][i]=1;}
      }
      else{
        col--;
        for(int i=0;i<6;i++){dp[nx][i]=0;}
        dp[nx][col]=1;
      }
    }
    else{
      long long mg=k-height(nx);
      long long lef=2*nx,rig=2*nx+1;
      vector<long long> lv,rv;
      if(st.find(lef)==st.end()){lv=gen(mg);}
      else{lv=dp[lef];}
      if(st.find(rig)==st.end()){rv=gen(mg);}
      else{rv=dp[rig];}
      dp[nx]=merge(lv,rv);
      if(mp[nx]!=0){
        long long col=mp[nx]-1;
        for(int i=0;i<6;i++){
          if(i!=col){dp[nx][i]=0;}
        }
      }
    }
    // cout << nx << ':';
    // for(int i=0;i<6;i++){cout << dp[nx][i] << ' ';}cout << '\n';
  }
  long long res=0;
  for(auto &nx : dp[1]){res+=nx;res%=mod;}
  cout << res << '\n';
  return 0;
}