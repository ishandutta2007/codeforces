#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

long long factorial[524288];
long long invfact[524288];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<524288;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[524287]=modular_inverse(factorial[524287]);
  for(i=524286;i>=0;i--){
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
    int n,m;
    cin >> n >> m;
    int kill,elem,delta;

    if(m<=2505){
      vector<int> st;
      for(int i=0;i<m;i++){
        int p,q;
        cin >> p >> q;
        q--;
        vector<int> nst;
        for(auto &nx : st){
          if(nx>=q){nst.push_back(nx+1);}
          else{nst.push_back(nx);}
        }
        st.swap(nst);
        st.push_back(q+1);

        sort(st.begin(),st.end());
        decltype(st)::iterator result = std::unique(st.begin(), st.end());
        st.erase(result, st.end());
      }
      kill=st.size();
    }
    else{
      bitset<200064> bs;
      for(int i=0;i<m;i++){
        int p,q;
        cin >> p >> q;
        q--;
        bs=((bs^((bs>>q)<<q))|((bs>>q)<<(q+1)));
        bs.set((q+1));
        //for(int j=0;j<8;j++){cout << bs[j];}cout << '\n';
      }
      kill=bs.count();
      //cout << kill << '\n';
      //cout << elem << ' ' << delta << '\n';
    }
    elem=n;
    delta=(n-1)-kill;
    cout << calcnCr(elem+delta,delta) << '\n';
  }
  return 0;
}