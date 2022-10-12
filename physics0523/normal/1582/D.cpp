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
    int nn=n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i].first;
      a[i].second=i;
    }
    sort(a.begin(),a.end());
    if(a[n-1].first+a[n-2].first==0){reverse(a.begin(),a.end());}
    vector<int> b(n);
    n--;
    while(n>=0){
      if(n%2==0){
        b[a[n].second]=a[n-2].first;
        b[a[n-1].second]=a[n-2].first;
        b[a[n-2].second]=-(a[n].first+a[n-1].first);
        n-=3;
      }
      else{
        b[a[n].second]=-a[n-1].first;
        b[a[n-1].second]=a[n].first;
        n-=2;
      }
    }
    for(int i=0;i<nn;i++){
      if(i){cout << ' ';}
      cout << b[i];
    }cout << '\n';
  }
  return 0;
}