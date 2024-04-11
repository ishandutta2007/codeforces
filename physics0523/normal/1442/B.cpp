#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    vector<int> iva(n+1),fl(n+1,1);
    for(int i=0;i<n;i++){
      cin >> a[i];
      iva[a[i]]=i;
    }
    for(int i=0;i<m;i++){
      cin >> b[i];
      fl[b[i]]=0;
    }
    long long res=1;
    for(int i=0;i<m;i++){
      fl[b[i]]=1;
      int cp=iva[b[i]];
      long long ck=0;
      if(cp!=0){ck+=fl[a[cp-1]];}
      if(cp!=(n-1)){ck+=fl[a[cp+1]];}
      res*=ck;res%=mod;
    }
    cout << res << '\n';
  }
  return 0;
}