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
    long long sig=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    if(sig==0){cout << "0\n";continue;}
    sort(a.begin(),a.end());
    long long res=0;
    for(int i=0;i<n-1;i++){res+=a[i];}
    cout << max(1ll,a[n-1]-res) << '\n';
  }
  return 0;
}