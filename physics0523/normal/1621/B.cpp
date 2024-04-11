#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> l(n),r(n),c(n);
    vector<long long> num(n,0),res(n,0);
    long long lg=0,lc=0;
    for(int i=0;i<n;i++){
      cin >> l[i] >> r[i] >> c[i];
      if((r[i]-l[i]+1)>lg){
        lg=(r[i]-l[i]+1);
        lc=c[i];
      }
      else if((r[i]-l[i]+1)==lg){
        lc=min(lc,c[i]);
      }
      num[i]=lg;res[i]=lc;
    }
    long long lm=2e9,rm=-2e9;
    lc=0;
    long long rc=0;
    for(int i=0;i<n;i++){
      if(l[i]<lm){
        lm=l[i];
        lc=c[i];
      }
      else if(lm==l[i]){
        lc=min(lc,c[i]);
      }
      if(rm<r[i]){
        rm=r[i];
        rc=c[i];
      }
      else if(rm==r[i]){
        rc=min(rc,c[i]);
      }
      if((rm-lm+1)>num[i]){
        num[i]=(rc-lc+1);
        res[i]=lc+rc;
      }
      else if((rm-lm+1)==num[i]){
        res[i]=min(res[i],lc+rc);
      }
    }
    for(int i=0;i<n;i++){
      //cout << num[i] << ' ' << res[i] << '\n';
      cout << res[i] << '\n';
    }
  }
  return 0;
}