#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<int> nx(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  map<long long,int> mp;
  long long sig=0;
  for(int i=0;i<3*n;i++){
    int ri=(i%n);
    nx[mp[sig]]=ri;
    mp[sig]=ri;
    sig+=a[ri];
  }
  int res=n;
  for(int i=0;i<n;i++){
    int len=1,p=nx[i];
    if(p==-1){continue;}
    nx[i]=-1;
    while(p!=i){
      len++;
      int np=nx[p];
      nx[p]=-1;
      p=np;
    }
    res=min(n-len,res);
  }
  cout << res << '\n';
  return 0;
}