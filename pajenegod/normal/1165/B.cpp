#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> A(n);
    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    int days = 0;
    for (auto a: A)
    {
        if (a < days+1)
            continue;
        days += 1;
    }
    cout << days << '\n';
}