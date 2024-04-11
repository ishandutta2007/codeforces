#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int p=0,q=0,cs=0,res=0;
  while(1){
    //cout << p << ' ' << q  << ' ' << cs << '\n';
    if(p==q){
      if(q==n){break;}
      cs+=a[q];q++;
      if(cs<=m){res=max(q-p,res);}
      continue;
    }
    if(cs>=m){cs-=a[p];p++;}
    else{
      if(q==n){break;}
      cs+=a[q];q++;
      if(cs<=m){res=max(q-p,res);}
    }
  }
  cout << res << '\n';
  return 0;
}