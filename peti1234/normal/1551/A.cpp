#include<bits/stdc++.h>
using namespace std;
int main() {
int w, n;
cin >> w;
while (w--) {
cin >> n;
cout << n/3+(n%3==1) << " " << n/3+(n%3==2) << endl;
}
return 0;
}