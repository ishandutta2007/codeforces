#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin >> t;
while(t--) {
int n;
cin >> n;
if (n%2) {
cout << "-1\n";
continue;
}
cout << n/2 << " 0 0\n";
}
return 0;
}