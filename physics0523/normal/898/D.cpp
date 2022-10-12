#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n),b(2097152);
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[1048576+a[i]]++;
  }
  int cnt=0,res=0;
  for(int i=m;i<2097152;i++){
    cnt-=b[i-m];
    cnt+=b[i];
    if(cnt>=k){
      int over=cnt-(k-1);
      res+=over;
      cnt-=over;
      b[i]-=over;
    }
  }
  cout << res << '\n';
  return 0;
}