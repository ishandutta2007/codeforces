#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int p[n];
  for(int i = 0;i<n;i++)cin >> p[i];
  int cnt = 0;
  for(int i = 0;i<n;i++)
    for(int j = n-1;j>i;j--)if(p[i]>p[j])cnt++;
  int q;
  cin >> q;
  int l,r;
  cnt%=2;
  for(int i = 0;i<q;i++){
    cin >> l >> r;
    cnt+=(r-l+1)/2;
    cnt%=2;
    cout << ((cnt==1) ? "odd\n" : "even\n");
  }
  return 0;
}