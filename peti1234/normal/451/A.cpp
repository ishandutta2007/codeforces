#include<bits/stdc++.h>

using namespace std;
int n, m;
int main() {
cin >> n >> m;
cout << (min(n, m)%2 ? "Akshat" : "Malvika") << endl;
}