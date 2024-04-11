#include<bits/stdc++.h>
#define MX 300005

using namespace std;
using Data=vector<vector<int>>;

//Wolfram Alpha : Table[NextPrime[10^9+100,-k],{k,10}]
//https://www.wolframalpha.com/input/?i=Table%5BNextPrime%5B10%5E9%2B100%2C-k%5D%2C%7Bk%2C10%7D%5D
vector<long long> prime={999999893,999999929,999999937,1000000007,1000000009,1000000021};

long long nCr_modp(long long n,long long r,long long p){
  long long res=1;
  for(int i=1;i<=r;i++){
    res*=(n+1-i);res%=p;
    while((res%i)!=0){res+=p;}
    res/=i;res%=p;
  }
  return res%p;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,g;
  cin >> n;
  unordered_set<int> st;
  for(int i=0;i<n;i++){
    int v,cv=1;
    cin >> v;
    if(i==0){g=v;}else{g=gcd(v,g);}
    for(int j=2;j*j<=v;j++){
      if((v%j)!=0){continue;}
      cv*=j;
      while((v%j)==0){v/=j;}
    }
    cv*=v;
    st.insert(cv);
  }
  if(g!=1){cout << "-1\n";return 0;}
  n=st.size();
  vector<int> bk(MX,0);
  for(auto e : st){bk[e]=1;}
  if(bk[1]==1){cout << "1\n";return 0;}

  Data dt(8);
  for(int i=2;i<MX;i++){
    int c=0,mi=i;
    for(int j=2;j*j<=mi;j++){
      if((mi%j)!=0){continue;}
      if(mi%(j*j)==0){c=-1;mi=1;break;}
      c++;mi/=j;
    }
    if(c==-1){continue;}
    if(mi!=1){c++;}
    int cnt=0;
    for(int j=i;j<MX;j+=i){cnt+=bk[j];}
    if(cnt!=0){dt[c].push_back(cnt);}
  }

  for(int r=2;;r++){
    for(auto mod : prime){
      long long cnt=0;
      for(int j=1;j<8;j++){
        for(auto e : dt[j]){
          long long cv=nCr_modp(e,r,mod);
          if(j%2==1){cnt+=cv;}
          else{cnt+=mod;cnt-=cv;}
          cnt%=mod;
        }
      }
      if(nCr_modp(n,r,mod) != cnt){cout << r << '\n';return 0;}
    }
  }
}