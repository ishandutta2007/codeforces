#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int cost (char a, char b) {
    return (int)min({max(a, b) - min(a, b), a - 'a' + 'z' - b + 1, b - 'a' + 'z' - a + 1});
}

int main() {
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;

    p -= 1;

    string s;
    cin >> s;

    int start = -1, end = -1;

    for (int i = 0; i < n/2; i++) {
        if (start == -1 and cost(s[i], s[n - i - 1]) > 0)
            start = end = i;
        else if (cost(s[i], s[n - i - 1]) > 0)
            end = i;
    }

    if (start == -1) {
        cout << "0\n";
        return 0;
    }

    if (p < n/2) {
        int c = 0;
        for (int i = start; i <= end; i++) {
            c += cost(s[i], s[n - i - 1]);
        }

        if (p >= end) c += p - start;
        else if (p <= start) c += end - p;
        else {
            c += min(end - p + end - start, p - start + end - start);
        }

        cout << c << "\n";
        return 0;
    }

    start = n - start - 1;
    end = n - end - 1;

    swap(start, end);

    int c = 0;
    for (int i = start; i <= end; i++) {
        c += cost(s[i], s[n - i - 1]);
    }

    if (p >= end) c += p - start;
    else if (p <= start) c += end - p;
    else c += min(end - p + end - start, p - start + end - start);

    cout << c << " ";

    return 0;
}