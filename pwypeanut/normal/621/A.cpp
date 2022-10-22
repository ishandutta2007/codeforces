#include <bits/stdc++.h>
using namespace std;

int T;
vector<int> even, odd;

int main() {
    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    long long sum = 0;
    for (int i = 0; i < even.size(); i++) sum += even[i];
    for (int i = odd.size() % 2; i < odd.size();i++) sum += odd[i];
    cout << sum << endl;
}