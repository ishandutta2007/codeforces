#include <iostream>
#include <vector>

using namespace std;
const int N = 2e2;
const int INF = 2e9;

int a[N];
vector <int> res;

int main() {
    int n{}, k{};
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (true) {
        int low{INF}, num{};
        for (int i = 1; i <= n; i++)
            if (a[i] < low) {
                low = a[i];
                num = i;
            }
        if (low > k)
            break;
        k -= low;
        res.push_back(num);
        a[num] = INF;
    }
    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}