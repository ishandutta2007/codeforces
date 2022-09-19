#include<bits/stdc++.h>
using namespace std;
int x, n;
string s;
int main() {
cin >> n;
while (n--) {
cin >> s;
(s[1]=='+' ? x++ : x--);
}
cout << x << endl;
return 0;
}