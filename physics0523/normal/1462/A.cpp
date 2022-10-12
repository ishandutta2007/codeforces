#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int p=0,q=n-1;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      if(i%2==0){cout << a[p];p++;}
      else{cout << a[q];q--;}
    }
    cout << '\n';
  }
}