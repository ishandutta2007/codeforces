#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll h, n, i;
  cin >> h >> n;
  ll a[2*n];
  for (i=0; i<n; i++) {
    cin >> a[i];
    a[n+i]=a[i];
  }
  ll maxdown=0, delta=0, mins=0;
  for (i=0; i<n; i++){
    delta+=a[i];
    maxdown=min(maxdown, delta);
  }
  maxdown=-maxdown;
  if (maxdown>=h){
    for (i=0; i<2*n; i++){
      mins++;
      h+=a[i];
      if (h<=0){
        cout << mins << endl;
        return 0;
      }
    }
  }
  if (maxdown<h && delta>=0){
    cout << -1 << endl;
    return 0;
  }
  ll safer=(h-(maxdown+1))/(-delta); 
  mins+=safer*n;
  h+=safer*delta;
  for (i=0; i<=2*n; i++){
    mins++;
    h+=a[i];
    if (h<=0){
      cout << mins << endl;
      return 0;
    }
  }
}