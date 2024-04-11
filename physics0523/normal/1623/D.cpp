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

long long modular_inverse(long long n){
  return power(n,mod-2);
}

//https://www.wolframalpha.com/input/?i=%E2%88%91%5Bi%3D1..inf%5D+p%5Ei
long long infsum(long long prob){
  prob%=mod;
  long long res=prob;
  prob--;
  prob*=(mod-1);prob%=mod;
  return (res*modular_inverse(prob))%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,r;
    int a,b;
    int p,q;
    long long perc,hand=0,res=0;
    cin >> l >> r >> a >> b >> p >> q >> perc;
    long long prob=1;
    long long e1=(perc*modular_inverse(100))%mod;
    long long e2=((100ll-perc)*modular_inverse(100))%mod;
    int ca=a,cb=b,dx=1,dy=1;
    int ia,ib,ix=dx,iy=dy;
    while(1){
      bool ok=false;
      if(ca==p || cb==q){ok=true;}
      if(ca==l){dx=-1;}
      if(cb==r){dy=-1;}
      if(ca==1){dx=1;}
      if(cb==1){dy=1;}
      ca+=dx;cb+=dy;
      if(hand==0){ia=ca;ib=cb;ix=dx;iy=dy;}
      else if(ca==ia && cb==ib && ix==dx && iy==dy){break;}
      if(ok){
        long long del=(((hand*prob)%mod)*e1)%mod;
        res+=del;res%=mod;
        prob*=e2;prob%=mod;
        //cout << hand << '\n';
      }
      //cout << a << ' ' << b << '\n';
      hand++;
    }
    res*=modular_inverse((mod+1-prob)%mod);res%=mod;
    //cout << hand << ' ' << prob << ' ' << res << '\n';
    res+=hand*infsum(prob);res%=mod;
    //cout << infsum(prob) << '\n';
    cout << res << '\n';
  }
  return 0;
}