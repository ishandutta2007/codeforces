#include<bits/stdc++.h>
using namespace std;
int n;
string a, b;
int main() {
cin >> a >> b;
n=a.size();
for (int i=0; i<n; i++) {
cout << (a[i]!=b[i]);
}
cout << endl;
return 0;
}