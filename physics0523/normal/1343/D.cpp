#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
    }
    vector<int> im(2*k+5,0);
    int p=0,q=n-1;
    while(p<q){
      if(a[p]>a[q]){swap(a[p],a[q]);}
      im[0]+=2;
      im[a[p]+1]--;
      im[a[p]+a[q]]--;
      im[a[p]+a[q]+1]++;
      im[k+a[q]+1]++;
      p++;q--;
    }
    int res=1e9;
    for(int i=1;i<=2*k;i++){
      im[i]+=im[i-1];
      res=min(res,im[i]);
    }
    cout << res << '\n';
  }
  return 0;
}