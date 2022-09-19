#include<bits/stdc++.h>
using namespace std;
int n, d, el, db, x, y;
int main() {
cin >> n >> d;
while (n--) {
cin >> x;
y=max(0, (el+d-x)/d);
x+=d*y, db+=y;
el=x;
}
cout << db;
}