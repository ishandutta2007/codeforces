#include<bits/stdc++.h>

using namespace std;

long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

long long p9[20]={0};

int res=1000;
int n;
long long sml;

void sol(long long cx,int ch){
  string s=to_string(cx);
  if(s.size()==n){
    res=min(res,ch);
    return;
  }
  if((res-ch-1)<20){
    double est=p9[(res-ch-1)];
    est*=cx;
    if(est<4e18){
      long long act=p9[(res-ch-1)];
      act*=cx;
      if(act<sml){return;}
    }
  }

  vector<int> bk(10,0);
  for(auto &nx : s){bk[nx-'0']++;}

  for(long long i=9;i>=2;i--){
    if(bk[i]){sol(cx*i,ch+1);}
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  p9[0]=1;
  for(int i=1;i<20;i++){p9[i]=p9[i-1]*9;}

  long long x;
  cin >> n >> x;
  sml=llpow(10,n-1);

  sol(x,0);
  if(res>=500){res=-1;}
  cout << res << '\n';
  return 0;
}