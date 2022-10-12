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
    vector<long long> a(n+2,0);
    for(int i=1;i<=n;i++){cin >> a[i];}
    long long res=0;
    for(int i=1;i<=n;i++){
      if(a[i-1]<a[i] && a[i]>a[i+1]){
        long long tg=max(a[i-1],a[i+1]);
        res+=(a[i]-tg);
        a[i]=tg;
      }
    }
    for(int i=1;i<=(n+1);i++){res+=abs(a[i]-a[i-1]);}
    cout << res << '\n';
  }
  return 0;
}