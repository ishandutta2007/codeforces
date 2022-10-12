#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

bool jud(long long h,long long w,long long p,long long q,vector<long long> &a){
  vector<long long> ca;
  for(long long i=0;i<h;i++){
    for(long long j=0;j<w;j++){
      ca.push_back(abs(p-i)+abs(q-j));
    }
  }
  sort(ca.begin(),ca.end());
  return (a==ca);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long sig=0;
  for(auto &nx : a){
    cin >> nx;
    sig+=nx;
  }
  sort(a.begin(),a.end());

  for(long long h=1;h*h<=n;h++){
    long long w=(n/h);
    if(h*w!=n){continue;}
    long long p,q;
    q=a.back();
    if(q>=w){q=w-1;}
    p=(a.back()-q);
    while(0<=p && p<h && 0<=q && q<w){
      long long csig=0;
      csig+=h*llsankaku(q);
      csig+=h*llsankaku(max(0ll,w-q-1));
      csig+=w*llsankaku(p);
      csig+=w*llsankaku(max(0ll,h-p-1));
      if(sig==csig){
        if(jud(h,w,p,q,a)){
          cout << h << ' ' << w << '\n';
          cout << p+1 << ' ' << q+1 << '\n';
          return 0;
        }
      }
      p++;q--;
    }
  }
  cout << "-1\n";
  return 0;
}