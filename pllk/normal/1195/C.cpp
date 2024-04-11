#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[101010];
int b[101010];
ll da[101010];
ll db[101010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        da[i] = da[i-1];
        db[i] = db[i-1];
        da[i] = max(da[i],a[i]+db[i-1]);
        db[i] = max(db[i],b[i]+da[i-1]);
    }
    cout << max(da[n],db[n]) << "\n";
}