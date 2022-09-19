#include<bits/stdc++.h>
using namespace std;
int x, n;
string s;
int main() {
cin >> n;
cin >> s;
for (int i=1; i<n; i++) x+=(s[i]==s[i-1]);
cout << x << endl;
return 0;
}