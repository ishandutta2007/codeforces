#include <iostream>

using namespace std;

typedef long long ll;

int n;
int c1[3000];
int c2[3000];
ll x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x += c1[a+b];
        c1[a+b]++;
        x += c2[a-b+1000];
        c2[a-b+1000]++;
    }
    cout << x << "\n";
}