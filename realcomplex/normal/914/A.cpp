#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;int l,v,ans=INT_MIN;for(int i = 0;i<n;i++){cin >> l;if(l<0)ans=max(ans,l);else if(l>0){v=sqrt(l);if(v*v!=l)ans=max(ans,l);}}cout << ans;return 0;
}