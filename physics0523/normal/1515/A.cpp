#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    long long sig=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      sig+=a[i];
    }
    if(sig==x){cout << "NO\n";}
    else{
      cout << "YES\n";
      sort(a.begin(),a.end());
      sig=0;
      for(int i=0;i<n;i++){
        sig+=a[i];
        if(sig==x){swap(a[i],a[i+1]);}
      }
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << a[i];
      }cout << '\n';
    }
  }
  return 0;
}