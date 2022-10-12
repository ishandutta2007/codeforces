#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using pl=pair<long long,long long>;

#define bsize 524288

long long sum(long long i,long long bit[]){
  long long s=0;
  while(i>0){
    s+=bit[i];
    if(s>=mod){s-=mod;}
    i-=i&(-i);
  }
  return s;
}
void add(long long i,long long x,long long bit[]){
  while(i<=bsize){
    bit[i]+=x;
    if(bit[i]>=mod){bit[i]-=mod;}
    i+=i&(-i);
  }
}

long long bitsg[bsize+5]={0},bitd[bsize+5]={0};

long long mod_nomalize(long long x){
  if(x>=0){return x%mod;}
  x*=-1;x%=mod;x=mod-x;
  if(x==mod){x=0;}
  return x;
}

void raq(long long st,long long fi,long long x){
  long long mx=mod_nomalize(x);
  add(st,mod_nomalize((-mx*(st-1))),bitsg);
  add(fi+1,mod_nomalize(mx*fi),bitsg);

  add(st,mx,bitd);
  add(fi+1,mod_nomalize(mod-mx),bitd);
}

long long rsq(long long st,long long fi){
  st--;
  long long stv,fiv;
  fiv=(sum(fi,bitsg)+sum(fi,bitd)*fi)%mod;
  stv=(sum(st,bitsg)+sum(st,bitd)*st)%mod;
  return mod_nomalize(fiv-stv);
}

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
  int n;
  cin >> n;
  vector<long long> x(n),y(n),s(n);
  vector<pl> ev;
  map<long long,long long> tag;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i] >> s[i];
    tag[x[i]]=y[i];
    tag[y[i]]=x[i];

    if(s[i]==0){
      ev.push_back({y[i],2});
      ev.push_back({x[i],0});
    }
    else{
      ev.push_back({y[i],2});
      ev.push_back({x[i],1});
    }
  }

  sort(ev.begin(),ev.end());

  long long inv2=modular_inverse(2);

  int len=ev.size();
  long long res=ev[len-1].first+1;

  map<long long,int> comp;
  for(int i=0;i<len;i++){comp[ev[i].first]=i+1;}

  for(int i=len-1;i>=1;i--){
    long long cv=rsq(comp[ev[i].first],comp[ev[i].first]);
    if(ev[i].second==1){cv++;cv%=mod;}
    if(ev[i].second!=2){
      raq(comp[tag[ev[i].first]],comp[ev[i].first],cv);
      long long sd=ev[i].first-tag[ev[i].first];
      //cout << tag[ev[i].first] << ',' << ev[i].first << ':' << cv << '\n';
      res+=sd*cv;res%=mod;
    }
  }

  cout << res << '\n';
  return 0;
}