#include <iostream>
#include <vector>
using namespace std;
vector<int> arr(2000001);

void mo(int from, int to) {
    for (int i = to; i > from; --i) 
        swap(arr[i], arr[i - 1]);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) arr[i] = i;
    for (int i = 0; i <= n; i += a) {
        if ((n - i) % b == 0) {
            for (int j = a; j <= i; j += a) mo(j - a + 1, j);
            for (int j = i + b; j <= n; j += b) mo(j - b + 1, j);
            for (int i = 1; i <= n; ++i) cout << arr[i] << ' ';
            return 0;
        }
    }
    cout << -1;
    return 0;
}