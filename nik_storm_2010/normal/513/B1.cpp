#include <iostream>

using namespace std;
const int N = 60;

long long power[N];
int a[N];

int main() {
    power[0] = 1;
    for (int i = 1; i < N; i++)
        power[i] = power[i - 1] * 2;
    int n{};
    long long k{};
    cin >> n >> k;
    k--;
    int l{1}, r{n};
    for (int i = 1; i <= n; i++) {
        if (k < power[n - i - 1]) {
            a[l++] = i;
        }
        else {
            a[r--] = i;
            k -= power[n - i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}