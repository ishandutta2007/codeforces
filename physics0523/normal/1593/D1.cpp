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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;nx+=1048576;}
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){cout << "-1\n";continue;}

    int g=a[1]-a[0];
    for(int i=1;i<n;i++){
      g=gcd(g,a[i]-a[i-1]);
    }
    cout << g << '\n';
  }
  return 0;
}