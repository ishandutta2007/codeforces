#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    int sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;sig%=x;
    }
    if(sig!=0){cout << n << '\n';continue;}
    int ls=1,rs=1;

    for(int i=0;i<n;i++){
      if(a[i]%x!=0){break;}
      ls++;
    }
    for(int i=0;i<n;i++){
      if(a[n-1-i]%x!=0){break;}
      rs++;
    }
    cout << n-min(ls,rs) << '\n';
  }
  return 0;
}