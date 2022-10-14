#include <bits/stdc++.h>
using namespace std;
using lint = long long;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    string rep;
    for (int i =0 ; i < K; i++) {
        rep.push_back(s[i]);
    }
    for (int i = K; i < N; i++) {
        rep.push_back(rep[i - K]);
    }
    if (rep >= s) {
        cout << rep.size() << "\n";
        cout << rep << "\n";
        return 0;
    }
    rep.clear();
    for (int i = 0; i < K; i++) {
        rep.push_back(s[i]);
    }
    for (int i = K - 1; i >= 0; i--) {
        if (rep[i] < '9') {
            rep[i]++;
            break;
        } else {
            rep[i] = '0';
        }
    }
    for (int i = K; i < N; i++) {
        rep.push_back(rep[i - K]);
    }
    cout << rep.size() << "\n";
    cout << rep << "\n";

}