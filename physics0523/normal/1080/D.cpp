#include<bits/stdc++.h>

using namespace std;

vector<long long> A000295_pref={0,0,1,4,11,26,57,120,247,502,1013,2036,4083,8178,16369,32752,65519,131054,262125,524268,1048555,2097130,4194281,8388584,16777191,33554406,67108837,134217700,268435427,536870882,1073741793,2147483616,4294967263,8589934558,17179869149,34359738332,68719476699,137438953434,274877906905,549755813848,1099511627735,2199023255510,4398046511061,8796093022164,17592186044371,35184372088786,70368744177617,140737488355280,281474976710607,562949953421262,1125899906842573,2251799813685196,4503599627370443,9007199254740938,18014398509481929,36028797018963912,72057594037927879,144115188075855814,288230376151711685,576460752303423428,1152921504606846915,2305843009213693890};
long long A000295(long long n){
  if(n>=A000295_pref.size()){return 3e18;}
  return A000295_pref[n];
}

long long p2(long long x){
  if(x<=61){return (1ll<<x);}
  return 3e18;
}

long long boundprod(long long x,long long y){
  double dest=x;
  dest*=y;
  if(dest>=4e18){return 3e18;}
  return min((long long)3e18,x*y);
}

long long A002450(long long n){
  if(n>=32){return 3e18;}
  return ((1ll<<(2*n))-1)/3;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    long long premah=0;
    bool na=true;
    for(long long dv=0;(dv<=n && A000295(dv+1)<=k);dv++){
      long long mih=A000295(dv+1);
      long long rem=min((long long)2e9,p2(dv)-1);
      rem=boundprod(rem,rem);
      rem=boundprod(rem,A002450(n-dv));
      // cout << mih << ' ' << premah+rem << '\n';
      if(k<=premah+rem){
        cout << "YES ";
        cout << n-dv << '\n';
        na=false;break;
      }
      premah=min((long long)3e18,premah+p2(2*dv));
    }
    if(na){cout << "NO\n";}
  }
  return 0;
}