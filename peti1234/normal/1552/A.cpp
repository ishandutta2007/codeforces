#include<bits/stdc++.h>
using namespace std;
int w, n;
int main() {
cin >> w;
while (w--) {
cin >> n;
int db=0;
string s, t;
cin >> s;
t=s;
sort(t.begin(), t.end());
for (int i=0; i<n; i++) {
db+=(t[i]==s[i]);
}
cout << n-db << endl;
}
return 0;
}