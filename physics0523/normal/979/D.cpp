#include<bits/stdc++.h>
#define MXM 100005
#define SML 100

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<int> bk(MXM,0);
  vector<set<int>> st(SML+5);
  while(t>0){
    t--;
    int t;
    cin >> t;
    if(t==1){
      int u;
      cin >> u;
      bk[u]=1;
      for(int i=1;i<=SML;i++){
        if(u%i==0){st[i].insert(u);}
      }
    }
    else{
      int x,k,s;
      cin >> x >> k >> s;
      if(x%k){cout << "-1\n";continue;}
      if(k<=SML){
        if(st[k].empty()){cout << "-1\n";continue;}
        if(x+(*st[k].begin())>s){cout << "-1\n";continue;}
        int l=0;
        for(int tg=20;tg>=0;tg--){
          if((x&(1<<tg))==0){
            int nl=(l+(1<<tg));
            auto it=st[k].lower_bound(nl);
            if(it!=st[k].end() && x+(*it)<=s && nl<=(*it) && (*it)<nl+(1<<tg)){l+=(1<<tg);}
          }
          else{
            if((*st[k].lower_bound(l))&(1<<tg)){l+=(1<<tg);}
          }
        }
        cout << l << '\n';
      }
      else{
        int res=-1;
        for(int i=k;i<MXM;i+=k){
          if(bk[i]){
            if(x+i<=s){
              if(res==-1){res=i;}
              if((x^res)<(x^i)){res=i;}
            }
          }
        }
        cout << res << '\n';
      }
    }
  }
  return 0;
}