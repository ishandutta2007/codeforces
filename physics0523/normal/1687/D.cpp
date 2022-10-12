//try systest
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

uint32_t xor64(void){
  static uint64_t x = 88172645463325252ULL;
  x = x ^ (x << 13); x = x ^ (x >> 7);
  return x = x ^ (x << 17);
}

long long sq(long long x){
  long long s=(sqrt(x)+1);
  while(s*s>x){s--;}
  return s;
}

long long f(long long x){
  long long s=sq(x);
  // cerr << x << ' ' << s << '\n';
  if(x<=s*(s+1)){return 0;}
  return (s+1)*(s+1)-x;
}

bool jud(long long k,vector<long long> &a){
  for(auto &nx : a){
    if(f(nx+k)){return false;}
  }
  return true;
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int hit=engine()%114514;
  for(int i=0;i<hit;i++){xor64();}

  int n;
  cin >> n;
  vector<long long> a;
  set<long long> st;
  for(int i=0;i<n;i++){
    long long val;
    cin >> val;
    st.insert(val);
  }
  n=st.size();
  for(auto &nx : st){a.push_back(nx);}
  shuffle(a.begin(),a.end(),engine);

  int sz=300;
  long long k=0;
  while(1){
    for(int l=0;l<n;l+=sz){
      int r=min(n-1,l+sz-1);
      int i=l,j=l;
      while(1){
        long long fv=f(a[i]+k);
        if(fv){k+=fv;j=i;}
        i++;
        if(i==r+1){i=l;}
        if(i==j){break;}
      }
    }
    if(jud(k,a)){cout << k << '\n';return 0;}
  }
  return 0;
}