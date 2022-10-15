#include <iostream>

#define lli long long int

using namespace std;

int n;
lli p[10+1];
lli e[10+1];
lli z;
int t;
lli s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > 0) p[t]++;
        if (t == 0) z++;
        if (t < 0) e[-t]++;
    }
    for (int i = 1; i <= 10; i++) {
        s += p[i]*e[i];
    }
    s += z*(z-1)/2;
    cout << s << endl;
}