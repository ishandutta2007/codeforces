#include<bits/stdc++.h>

using namespace std;

// int main(){
//   for(int i=1;i<=20;i++){
//     int x=i;
//     cout << i << " ";
//     while(x%10!=0 && x<100){
//       x+=(x%10);
//       cout << x%20 << " ";
//     }cout << "\n";
//   }
//   return 0;
// }

int f(int x){
  while(!(x%20==2 || x%20==6 || x%10==0)){
    x+=(x%10);
  }
  if(x%10==0){return x;}
  else if(x%20==2){return 2;}
  else{return 6;}
}

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
    for(auto &nx : a){
      cin >> nx;
      nx=f(nx);
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}