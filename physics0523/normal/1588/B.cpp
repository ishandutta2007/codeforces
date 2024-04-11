#include<bits/stdc++.h>

using namespace std;

long long ask(long long l,long long r){
  if(l==r){return 0;}
  cout << "? " << l << ' ' << r << '\n';
  fflush(stdout);
  long long res=0;
  cin >> res;
  return res;
}

void ans(long long i,long long j,long long k){
  cout << "! " << i << ' ' << j << ' ' << k << '\n';
  fflush(stdout);
}

long long llsankaku(long long x){return ((1+x)*x)/2;}
long long invsankaku(long long x){
  if(x==0){return 0;}
  long long l=0,r=1072114514,te;
  while(l<=r){
    te=(l+r)/2;
    long long ls=llsankaku(te);
    if(ls==x){return te;}
    if(ls<x){l=te+1;}else{r=te-1;}
  }
  return -1;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long all=ask(1,n);
    long long l=1,r=n;
    long long mid,mv;
    while(1){
      long long te=(l+r)/2;
      long long val=ask(l,te);
      if(val==0){l=te;}
      else if(val==all){r=te;}
      else{mid=te;mv=val;break;}
    }
    long long fs=mv,bs=ask(mid+1,r);
    long long ivf=invsankaku(fs);
    long long ivs=invsankaku(bs);
    long long ri,rj,rk;
    if(ivf!=-1 && ask(mid-ivf,r)==all){
      cerr << "t1\n";
      ri=mid-ivf;
      long long st=ri,fi=r;
      while(st<=fi){
        long long te=(st+fi)/2;
        if(ask(ri,te)==llsankaku(te-ri)){st=te+1;}
        else{fi=te-1;}
      }
      rj=fi+1;
      //cerr << all << ' ' << llsankaku(rj-1-ri) << '\n';
      long long remlen=invsankaku(all-llsankaku(rj-1-ri));
      //cerr << rj << ' ' << remlen << '\n';
      rk=rj+remlen;
    }
    else{
      cerr << "t2\n";
      rk=mid+(ivs+1);
      long long st=l,fi=rk;
      while(st<=fi){
        long long te=(st+fi)/2;
        if(ask(te,rk)==llsankaku(rk-te)){fi=te-1;}
        else{st=te+1;}
      }
      rj=st;
      long long remlen=invsankaku(all-llsankaku(rk-rj));
      ri=rj-1-remlen;
    }
    ans(ri,rj,rk);
  }
  return 0;
}