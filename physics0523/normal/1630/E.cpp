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

const long long MAX=1048576;

long long factorial[MAX];
long long invfact[MAX];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<MAX;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[MAX-1]=modular_inverse(factorial[MAX-1]);
  for(i=MAX-2;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long calcnCr(long long n,long long k){
  if(k<0 || n<k){return 0;}
  return (factorial[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    if(n<=2){
      vector<int> a(n);
      for(auto &nx : a){cin >> nx;}
      if(n==1){cout << "1\n";}
      if(n==2){
        if(a[0]==a[1]){cout << "1\n";}
        else{cout << "2\n";}
      }
      continue;
    }
    vector<long long> bk(n,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v--;
      bk[v]++;
    }

    bool issame=false;
    for(int i=0;i<n;i++){
      if(bk[i]==n){issame=true;}
    }
    if(issame){
      cout << 1 << '\n';
      continue;
    }

    vector<long long> bl;
    for(auto &nx : bk){
      if(nx>0){bl.push_back(nx);}
    }

    long long res=0,div=0;
    vector<long long> mem(n+1,-1),dm(n+1,-1);
    for(long long i=1;i<=n;i++){
      long long g=gcd(n,i);
      if(mem[g]!=-1){
        res+=((mem[g]*dm[g])%mod);res%=mod;
        div+=dm[g];div%=mod;
        continue;
      }
      mem[g]=0;dm[g]=0;
      bool isok=true;
      long long blk=(n/g);
      for(auto &nx : bl){
        if(nx%blk){isok=false;break;}
      }
      if(!isok){continue;}

      dm[g]=1;
      long long sz=g;
      for(auto &nx : bl){
        long long dec=(nx/blk);
        dm[g]*=calcnCr(sz,dec);dm[g]%=mod;
        sz-=dec;
      }
      sz=g;
      for(auto &nx : bl){
        long long cs=(nx/blk);
        if(cs>=2){
          long long del=(cs*(cs-1))%mod;
          del*=factorial[sz-2];del%=mod;
          del*=invfact[sz];del%=mod;
          del*=sz;del%=mod;
          del*=blk;del%=mod;
          mem[g]+=del;mem[g]%=mod;
        }
      }
      res+=((mem[g]*dm[g])%mod);res%=mod;
      div+=dm[g];div%=mod;
    }
    //cout << res << ' ' << div << '\n';
    res*=modular_inverse(n);res%=mod;
    div*=modular_inverse(n);div%=mod;
    cout << (mod+n-((res*modular_inverse(div))%mod))%mod << '\n';
  }
  return 0;
}