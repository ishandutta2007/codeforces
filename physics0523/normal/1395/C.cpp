#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}
  int res=(1<<10)-1;
  for(int tg=9;tg>=0;tg--){
    res^=(1<<tg);
    bool iscut=true;
    for(int i=0;i<n;i++){
      bool cf=true;
      for(int j=0;j<m;j++){
        if(((a[i]&b[j])|res)==res){cf=false;}
      }
      if(cf){iscut=false;break;}
    }
    if(!iscut){res^=(1<<tg);}
  }
  cout << res << '\n';
  return 0;
}