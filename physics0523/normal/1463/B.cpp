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
    vector<long long> a(n);
    long long p=0,q=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(i%2==0){p+=a[i];}
      else{q+=a[i];}
    }
    long long tg;
    if(p>q){tg=1;}else{tg=0;}
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      if(tg==(i%2)){cout << 1;}
      else{cout << a[i];}
    }cout << "\n";
  }
  return 0;
}