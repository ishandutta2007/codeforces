#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    // T = 1;
    while (T--) solve();
    return 0;
}

int solve() {
    lint a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);
    lint d = b - a;

    lint ans = 2 * d;

    lint l = 1, r = d;
    while (l < r) {
        lint m = (l + r) / 2;
        if (d * 2 > m * (m + 1)) {
            l = m + 1;
            ans = m + 1;
        } else {
            r = m;
        }
    }
    if (d <= 1) ans = d;
    while (((ans + 1) * ans) / 2 % 2 != d % 2) ans++;

    cout << ans << "\n";
}

/*
for(int t=1;t<=T;++t){
  cin>>A>>B;
  A=max(A,B)-min(A,B);
  Le=1; Ri=A;
  while(Le<Ri){
   Mid=(Le+Ri)/2;
   if(A*2>Mid*(Mid+1)){
    Ans=Mid+1;
    Le=Mid+1;
   } else Ri=Mid;
  }
  if(A<=1) Ans=A;
  while(((Ans+1)*Ans)/2%2!=A%2) Ans++;
  cout<<Ans<<'\n';
 }

*/