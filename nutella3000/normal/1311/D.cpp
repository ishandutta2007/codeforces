#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = (1 << 19);



signed main() {
    //freopen("inpur.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    for(int q = 0;q < test;q++) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = inf;
        int ans_a, ans_b, ans_c;
        for(int A = 1;A <= 10000;A++) {
            for(int B = A;B <= 20000;B += A) {
                int sum = abs(A - a) + abs(B - b) + min(c % B, B - c % B);
                if (ans > sum) {
                    ans = sum;
                    ans_a = A;
                    ans_b = B;
                    if (c % B < B - c % B) ans_c = c - c % B;
                    else ans_c = c + B - c % B;
                }
            }
        }
        cout << ans << '\n';
        cout << ans_a << " " << ans_b << " " << ans_c << '\n';
    }

}