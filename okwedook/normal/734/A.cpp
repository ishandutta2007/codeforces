#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int count1 = 0, count2 = 0;
    for (auto i : s) count1 += (i == 'D'), count2 += (i == 'A');
    if (count2 > count1) cout << "Anton";
    else if (count1 > count2) cout << "Danik";
    else cout << "Friendship";
    return 0;
}