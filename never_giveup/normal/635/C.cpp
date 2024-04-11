#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e6;

ll s, x;

ll sz = 0, st[62], stp[62];

int main()
{
    cin >> s >> x;
    stp[0] = 1;
    for (int i = 1; i < 61; i++)
        stp[i] = stp[i - 1] * 2;
    ll answer = 1;
    for (int i = 59; i >= 0; i--){
        if (stp[i] & x)
            answer *= 2;
        else
            st[sz] = i + 1, sz++;
    }
    s -= x;
    if (s == 0){
        cout << answer - 2;
        return 0;
    }
    for (int i = 0; i < sz && s > 0; i++)
        if (stp[st[i]] <= s)
            s -= stp[st[i]];
    if (s == 0)
        cout << answer;
    else
        cout << 0;
}