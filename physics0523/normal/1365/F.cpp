#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    multiset<pi> sa,sb;
    int p=0,q=n-1;
    while(p<=q){
      if(p==q){
        sa.insert({min(a[p],-1),max(a[p],-1)});
        sb.insert({min(b[p],-1),max(b[p],-1)});
      }
      else{
        sa.insert({min(a[p],a[q]),max(a[p],a[q])});
        sb.insert({min(b[p],b[q]),max(b[p],b[q])});
      }
      p++;q--;
    }
    if(sa==sb){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}