#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

bool can_build(LL num, vector<int> pows) {
    sort(all(pows), greater<int>());
    for (auto pow: pows)
        if ((1LL << pow) <= num)
            num -= 1LL << pow;
    return num == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    LL T;
    cin >> n >> T;
    vector<int> pows;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int num = c - 'a';
        if (i == n - 1)
            T -= 1LL << num;
        else if (i == n - 2)
            T += 1LL << num;
        else {
            pows.PB(num + 1);
            T += 1LL << num;
        }
    }
    if (can_build(T, pows))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}