#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100];
int s, t;
int a, b;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    cin >> s >> t;
    s--; t--;
    for (int i = s; i != t; i=(i+1)%n) a += d[i];
    for (int i = t; i != s; i=(i+1)%n) b += d[i];
    cout << min(a, b) << endl;
}