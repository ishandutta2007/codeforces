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
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    int res=0;
    int diff=0;
    for(int i=0;i<n;i++){
      res+=abs(a[i]-b[i]);
      diff+=a[i];
      diff-=b[i];
    }
    res=min(res,abs(diff)+1);
    cout << res << "\n";
  }
  return 0;
}