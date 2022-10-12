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
    int n,k;
    cin >> n >> k;
    vector<pi> a(n);

    for(int i=0;i<n;i++){
      cin >> a[i].first;
      a[i].second=i;
    }
    sort(a.begin(),a.end());
    vector<int> b(n);
    for(int i=0;i<n;i++){b[a[i].second]=i;}
    int nd=1;
    for(int i=1;i<n;i++){
      if(b[i-1]+1!=b[i]){nd++;}
    }
    if(nd<=k){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}