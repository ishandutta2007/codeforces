#include<bits/stdc++.h>

using namespace std;
int n, t[5], cnt, db;
int main() {
for (int i=1;i<5; ++i) cin >> t[i];
cin >> n;
for (int i=1; i<=n; i++) {
db=0;
for (int j=1; j<5; j++) if (i%t[j]==0) db++;
if (!db) cnt++;
}
cout << n-cnt;
return 0;
}