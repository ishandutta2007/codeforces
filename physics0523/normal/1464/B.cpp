#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

//Binary Indexed Tree
long long bit[525252]={0},bsize=524288;
long long sum(long long i){
    long long s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(long long i,long long x){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

long long seg(long long st,long long fi,long long fl){
  if(st>fi){return 0;}
  long long res=sum(fi)-sum(st-1);
  if(fl==0){res=(fi-st+1)-res;}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s;
  long long x,y;
  cin >> s;
  cin >> x >> y;
  long long res=llinf;
  long long n=s.size();
  s='*'+s;
  for(long long i=1;i<=n;i++){
    if(s[i]=='1'){add(i,1);}
  }
  long long ini=0,cv;
  for(long long i=1;i<=n;i++){
    if(s[i]!='1'){
      ini+=y*seg(1,i-1,1)+x*seg(i+1,n,1);
    }
    else{
      ini+=x*seg(1,i-1,0)+y*seg(i+1,n,0);
    }
  }
  ini/=2;

  res=ini;
  
  cv=ini;
  for(long long i=1;i<=n;i++){
    if(s[i]=='?'){
      cv-=y*seg(1,i-1,1)+x*seg(i+1,n,1);
      cv+=x*seg(1,i-1,0)+y*seg(i+1,n,0);
      add(i,1);
    }
    res=min(cv,res);
  }
  
  for(long long i=0;i<525252;i++){bit[i]=0;}
  for(long long i=1;i<=n;i++){
    if(s[i]=='1'){add(i,1);}
  }

  cv=ini;
  for(long long i=n;i>=1;i--){
    if(s[i]=='?'){
      cv-=y*seg(1,i-1,1)+x*seg(i+1,n,1);
      cv+=x*seg(1,i-1,0)+y*seg(i+1,n,0);
      add(i,1);
    }
    res=min(cv,res);
  }

  cout << res << '\n';
  return 0;
}