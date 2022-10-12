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
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    int fl=1;
    for(int i=0;i<n;i++){
      if(a[i]<min(i,n-1-i)){fl=0;}
    }
    if(n%2==0){
      if(a[(n/2)-1]==a[n/2] && a[n/2]==(n/2)-1){fl=0;}
    }
    if(fl){cout << "Yes\n";}else{cout << "No\n";}
  }
}