#include<bits/stdc++.h>

using namespace std;
long long mem[19][262144]={0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<long long> a(1<<n);
  for(int i=0;i<(1<<n);i++){
    cin >> a[i];
    for(int k=0;k<=n;k++){
      mem[k][(i>>k)]+=a[i];
    }
  }

  int mv=0;
  for(int i=0;i<q;i++){
    int t;
    cin >> t;
    if(t==1){
      int x;
      long long k;
      cin >> x >> k;
      x--;
      x^=mv;
      long long old=a[x];
      for(int tg=0;tg<=n;tg++){
        mem[tg][(x>>tg)]-=old;
        mem[tg][(x>>tg)]+=k;
      }
      a[x]=k;
    }
    if(t==2){
      int k;
      cin >> k;
      mv^=((1<<k)-1);
    }
    if(t==3){
      int k;
      cin >> k;
      mv^=(1<<k);
    }
    if(t==4){
      int l,r;
      cin >> l >> r;
      l--;r--;
      long long res=0;
      while(l<=r){
        //cout << '[' <<  l << ',' << r << "]\n";
        int cl=(mv^l);
        int tz=min(n,(int)__builtin_ctz((unsigned int)l));
        for(int tg=tz;tg>=0;tg--){
          int del=(1<<tg);
          if((l+del-1)>r){continue;}
          //cout << tg << ' ' << cl << ':';
          res+=mem[tg][(cl>>tg)];
          //cout << mem[tg][(cl>>tg)] << '\n';
          l+=del;
          break;
        }
      }
      cout << res << '\n';
    }
  }
  return 0;
}