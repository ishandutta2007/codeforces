#include <iostream>

using namespace std;

#define ll long long

int n;
ll a;
int d[202020];
ll s;

int main() {
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        s += d[i];
    }
    for (int i = 0; i < n; i++) {
        ll c = 0;
        if (a-(n-1) < d[i]) c += d[i]-(a-(n-1));
        if (a-(s-d[i]) > 0) c += a-(s-d[i])-1;
        cout << c << " ";
    }
    cout << "\n";
}