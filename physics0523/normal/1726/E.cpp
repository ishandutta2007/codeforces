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

// A000085[N] =
// pairing (1,2,...,N), there are [0,N/2] pairs
// https://oeis.org/A000085
vector<long long> A000085;
void prec(){
  A000085.resize(524288);
  A000085[0]=1;
  A000085[1]=1;
  for(long long i=2;i<524288;i++){
    A000085[i]=(A000085[i-1]+(i-1)*A000085[i-2])%mod;
  }
}

//
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cfact();
  prec();

  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long res=0;

    long long pmatch=1;
    for(long long i=0;i<=n;i+=4){
      long long sing=n-i;
      long long doub=i/2;

      long long del=calcnCr(sing+doub,doub);
      del*=pmatch;del%=mod;
      del*=power(2,i/4);del%=mod;
      del*=A000085[n-i];del%=mod;
      res+=del;res%=mod;

      pmatch*=((i/2)+1);pmatch%=mod;
    }
    cout << res << "\n";
  }
  return 0;
}

// i - p_i

// There are 3 types of subgraph

// x   - y
// |     |
// y+1 - x+1

// x - y

// x

// vector<int> inv(vector<int> &p){
//   vector<int> res(p.size());
//   for(int i=0;i<p.size();i++){
//     res[p[i]]=i;
//   }
//   return res;
// }
//
// int main(){
//   for(int n=2;n<=8;n++){
//     vector<int> p(n);
//     for(int i=0;i<n;i++){p[i]=i;}
//     int res=0;
//     do{
//       vector<int> q=inv(p);
//       int fl=1;
//       for(int i=0;i<n;i++){
//         if(abs(q[i]-p[i])>1){fl=0;break;}
//       }
//       if(fl){
//         for(int i=0;i<n;i++){
//           cout << p[i] << " ";
//         }cout << "\n";
//       }
//       res+=fl;
//     }while(next_permutation(p.begin(),p.end()));
//     cout << "total " << n << " : " << res << "\n";
//     cout << "\n";
//   }
//   return 0;
// }