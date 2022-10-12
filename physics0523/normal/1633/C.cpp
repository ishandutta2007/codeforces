#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

bool battle(long long hc,long long dc,long long hm,long long dm){
  long long cw=llceil(hm,dc);
  long long cl=llceil(hc,dm);
  if(cw<=cl){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long hc,dc;
    cin >> hc >> dc;
    long long hm,dm;
    cin >> hm >> dm;
    long long k,w,a;
    cin >> k >> w >> a;
    bool isok=false;
    for(long long i=0;i<=k;i++){
      long long hf=hc+a*(k-i);
      long long df=dc+w*i;
      isok|=battle(hf,df,hm,dm);
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}