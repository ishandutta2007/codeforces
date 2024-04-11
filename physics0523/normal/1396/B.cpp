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
    int sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    sort(a.begin(),a.end());
    if(a[n-1]>(sig/2)){cout << "T\n";}
    else if(sig%2==0){cout << "HL\n";}
    else{cout << "T\n";}
  }
  return 0;
}