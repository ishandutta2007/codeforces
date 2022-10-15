#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    if (min(n,m)%2 == 0) cout << "Malvika\n";
    else cout << "Akshat\n";
}