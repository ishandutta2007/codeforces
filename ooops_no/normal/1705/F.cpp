#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

string my_str = "";

int ask(string s) {
#ifdef LOCAL
    int cnt = 0;
    for (int j = 0; j < s.size(); j++) {
        cnt += my_str[j] == s[j];
    }
    return cnt;
#endif // LOCAL
    cout << s << endl;
    int a;
    cin >> a;
    if (a == s.size() || a == -1) {
        exit(0);
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (rnd() % 2) {
            my_str += "F";
        } else {
            my_str += "T";
        }
    }
    string s = "", ans = "", t = "";
    for (int i = 0; i < n; i++) {
        t += 'T';
        s += (i % 2 == 0 ? 'T' : 'F');
    }
    int i = 0, res1 = ask(t), res2 = ask(s);
    for (; i + 3 < n;) {
        t[i] = t[i + 1] = 'F';
        int nw = ask(t);
        t[i] = t[i + 1] = 'T';
        if (res1 + 2 == nw) {
            ans += "FF";
            i += 2;
        } else if (res1 - 2 == nw) {
            ans += "TT";
            i += 2;
        } else {
            string s_copy = s;
            if (s[i] == 'T') {
                s_copy[i] = 'F', s_copy[i + 1] = 'T', s_copy[i + 2] = 'F';
                int res3 = ask(s_copy);
                if (res2 - 3 == res3) {
                    ans += "TFT";
                } else if (res2 - 1 == res3) {
                    ans += "TFF";
                } else if (res2 + 1 == res3) {
                    ans += "FTT";
                } else {
                    ans += "FTF";
                }
            } else {
                s_copy[i] = 'T', s_copy[i + 1] = 'F', s_copy[i + 2] = 'T';
                int res3 = ask(s_copy);
                if (res2 - 3 == res3) {
                    ans += "FTF";
                } else if (res2 - 1 == res3) {
                    ans += "FTT";
                } else if (res2 + 1 == res3) {
                    ans += "TFF";
                } else {
                    ans += "TFT";
                }
            }
            i += 3;
        }
    }
    for (; i < n; i++) {
        t[i] = 'F';
        int nw = ask(t);
        t[i] = 'T';
        if (res1 > nw) {
            ans += 'T';
        } else {
            ans += 'F';
        }
    }
    ask(ans);
    return 0;
}