#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

string s;

ll answer = 0, ans = 0;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    while (i < n){
        while (s[i] >= 'a' && s[i] <= 'z')
            i++;
        bool first = 0;
        int add = 0;
        int ad1 = 0;
        while (i < n){
            int cnt = 0;
            int now = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9')
                cnt++, now = now * 10 + s[i] - '0', i++;
            if (!first)
                first = 1, add += now;
            else
            if (first)
                if (cnt == 3)
                    add = add * 1000 + now;
                else
                    ad1 += now;
            if (i >= n || s[i] != '.')
                break;
            else
                i++;
        }
        answer += add;
        ans += ad1;
    }
    answer += ans / 100;
    ans %= 100;
    string ret;
    while (answer > 0)
        ret.push_back(answer % 10 + 48), answer /= 10;
    if (ret.size() == 0)
        ret.push_back(48);
    reverse(ret.begin(), ret.end());
    int cnt = (int)(ret.size()) % 3;
    if (cnt == 0)
        cnt = 3;
    for (int i = 0; i < cnt; i++)
        cout << ret[i];
    for (int i = cnt; i < (int)ret.size(); i += 3){
        cout << '.';
        for (int j = i; j < min((int)ret.size(), i + 3); j++)
            cout << ret[j];
    }
    if (ans == 0)
        return 0;
    cout << '.';
    if (ans < 10)
        cout << '0' << ans;
    else
        cout << ans;
}