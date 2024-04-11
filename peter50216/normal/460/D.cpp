// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int i=0;i<(n);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI(x) scanf("%d",&x)
#define PI(x) printf("%I64d\n",x)
#define SEP(x) ((x)?'\n':' ')
typedef long long LL;
// }}}

vector<LL> ans;LL av=-1;
LL calc(const vector<LL>& v){
  LL a=0;
  REP(i,SZ(v))a^=v[i];return a;
}
void upd(const vector<LL>& v){
  LL r=calc(v);
  if(av==-1||av>r){
    av=r;ans=v;
  }
}
vector<LL> tmp;
LL l,r;
int k;
void dfs(int np,LL lb){
  if(np>=1&&np<=k)upd(tmp);
  if(np==k)return;
  for(LL x=lb;x<=r;x++){
    tmp.push_back(x);
    dfs(np+1,x+1);
    tmp.pop_back();
  }
}
int main(){
  scanf("%I64d%I64d",&l,&r);
  RI(k);
  if(k>=1)upd({l});
  if(k>=2){
    upd({l,l+1});
    for(LL i=l;i<=r;i++){
      if(i%2==0&&i+1<=r){
        upd({i,i+1});break;
      }
    }
  }
  if(k>=4){
    for(LL i=l;i<=r;i++){
      if(i%4==0&&i+3<=r){
        upd({i,i+1,i+2,i+3});break;
      }
    }
  }
  if(k==3){
    REP(i,41){
      LL a1=max(l,1LL<<i),a2=min(r,(1LL<<(i+1))-1);
      if(a1>a2)continue;
      int j=i+1;
      LL b1=1LL<<j,b2=1LL<<j;
      int c=0;
      PER(kk,41){
        if(a1&(1LL<<kk)){
          if(c==0){b1|=1LL<<kk;c=1;}
          else b2|=1LL<<kk;
        }
      }
      if(b1>=l&&b1<=r&&b2>=l&&b2<=r){
        upd({a1,b1,b2});
      }
    }
  }
  if(av>0&&k>3){
    dfs(0,l);
  }
  PI(av);
  printf("%d\n",SZ(ans));
  REP(i,SZ(ans))printf("%I64d%c",ans[i],SEP(i==SZ(ans)-1));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread