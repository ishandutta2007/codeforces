#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t,n,a[524288];
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    int sig=0;
    for(int i=1;i<=n;i++){
      //cout << i << '\n';
      cin >> a[i];
      sig+=a[i];
    }
    if(sig%n!=0){
      cout << -1 << '\n';
      continue;
    }
    cout << 3*(n-1) << '\n';
    for(int i=2;i<=n;i++){
      int l=i-(a[i]%i);
      if(l==i){l=0;}
      cout << 1 << ' ' << i << ' ' << l <<'\n';
      a[1]-=l;a[i]+=l;
      l=(a[i]/i);
      cout << i << ' ' << 1 << ' ' << l <<'\n';
      a[i]-=i*l;a[1]+=i*l;
    }
    for(int i=2;i<=n;i++){
      int l=(sig/n)-a[i];
      cout << 1 << ' ' << i << ' ' << l << '\n';
    }
  }
  return 0;
}