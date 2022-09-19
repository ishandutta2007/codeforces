#include<bits/stdc++.h>
using namespace std;
int w, si;
string s;
int main() {
cin >> w;
while (w--) {
cin >> s;
si=s.size();
if (si>10) {
cout << s[0] << si-2 << s[si-1]<< endl;
}
else {
cout << s << endl;
}
}
return 0;
}