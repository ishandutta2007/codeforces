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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    if(a[n-2]>a[n-1]){cout << "-1\n";continue;}
    bool done=false;
    for(int i=n-3;i>=0;i--){
      if(a[i]>a[i+1]){
        long long md=(a[i+1]-a[n-1]);
        if(md<=a[i+1]){
          cout << i+1 << '\n';
          for(int j=i;j>=0;j--){
            cout << j+1 << ' ' << i+2 << ' ' << n << '\n';
          }
        }
        else{cout << "-1\n";}
        done=true;
        break;
      }
    }
    if(!done){cout << "0\n";}
  }
  return 0;
}