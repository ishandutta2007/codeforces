#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n != 12 and (n % 10 == 1 or n % 10 == 7 or n % 10 == 9 or (n >= 10 and n <= 29) or (n >= 70 and n <= 79) or (n >= 90 and n <= 99)))
        cout << "NO";
    else
        cout << "YES";
    return 0;
}