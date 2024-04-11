#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int n;
int a[5555];
ll z;

ll laske(int s) {
    if (s >= (1<<(n+1))) return 0;
    ll v = laske(2*s)+a[2*s];
    ll o = laske(2*s+1)+a[2*s+1];
    z += abs(v-o);
    return max(v,o);
}

int main() {
    cin >> n;
    for (int i = 0; i < (1<<(n+1))-2; i++) cin >> a[2+i];
    laske(1);
    cout << z << "\n";
}