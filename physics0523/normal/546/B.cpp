#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  sort(a.begin(),a.end());
  int res=0;
  for(int i=1;i<n;i++){
    if(a[i-1]>=a[i]){
      res+=(a[i-1]-a[i]+1);
      a[i]=a[i-1]+1;
    }
  }
  cout << res << '\n';
  return 0;
}