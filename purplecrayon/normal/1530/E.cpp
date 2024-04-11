#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

//if any char appears exactly once, then the answer is 0
//else if there's only one distinct character the answer is n-1
//else the answer is 1
//
//
//zaazzzzz
//
//abbbbbba
//
//aabb
//
//a appears exactly twice: aa_____
//a appears exactly thrice: aaba_ b____
//if there are two distinct characters: ab
//otherwise: abaaaacbbbb____
//
//
//a
//0, 0, 1, 1,
void solve(){
    string s; cin >> s;
    ar<int, 26> cnt; cnt.fill(0);
    for (auto c : s) {
        cnt[c-'a']++;
    }

    for (int i = 0; i < 26; i++) if (cnt[i] == 1) {
        cout << char(i+'a');
        cnt[i]--;
        for (int j = 0; j < 26; j++) while (cnt[j]--) cout << char(j+'a');
        cout << '\n';
        return;
    }
    int n = sz(s);
    if (*max_element(cnt.begin(), cnt.end()) == n){ cout << s << '\n'; return; }


    string t="";
    for (int j = 0; j < 26; j++) if (cnt[j]) {
        t += char(j+'a');
        t += char(j+'a');
        cnt[j] -= 2;
        break;
    }
    {
        int a = t[0]-'a';
        for (int i = 2; i < n; i++) {
            if ((t.back() != a+'a') && cnt[a]) {
                t += char(a+'a');
                cnt[a]--;
                continue;
            }
            bool bad = 1;
            for (int j = 0; j < 26; j++) if (cnt[j] && j != a) {
                bad = 0;
                t += char(j+'a');
                cnt[j]--;
                break;
            }
            if (bad) break;
        }
        if (sz(t) == n){ cout << t << '\n'; return; }
    }

    cnt.fill(0);
    for (auto c : s) {
        cnt[c-'a']++;
    }

    int num_distinct = 0;
    for (int j = 0; j < 26; j++) if (cnt[j]) num_distinct++;

    int a = -1, b = -1;
    for (int j = 0; j < 26; j++) if (cnt[j]) {
        if (a == -1) a = j;
        else if (b == -1) b = j;
    }
    if (num_distinct == 2) {
        cout << char(a+'a'); cnt[a]--;
        while (cnt[b]--) cout << char(b+'a');
        while (cnt[a]--) cout << char(a+'a');
        cout << '\n';
        return;
    }

    t="";
    t += char('a'+a); cnt[a]--;
    t += char('a'+b); cnt[b]--;

    string st = t;
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 26; j++) if (cnt[j]) {
            string en = t[i-1]+string(1, char('a'+j));
            if (en == st) continue;
            cnt[j]--;
            t += char(j+'a');
            break;
        }
    }
    if (sz(t) == n){ cout << t << '\n'; return; }
    assert(false);

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) {
        solve();
#ifdef LOCAL
    cout.flush();
#endif
    }
}



//aabaaaaa
//abaaaa

//abaaaa