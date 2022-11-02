#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

vector<char> was(26);
vector<int> need(26);

string get(string s, char now, bool f){
    string t = "";
    auto was_copy = was;
    auto need_copy = need;
    for (int i = 0; i < s.size(); i++){
        if (was_copy[s[i] - 'a'] != '#'){
            t += was_copy[s[i] - 'a'];
        }
        else{
            while(need_copy[now - 'a']){
                if (f) now--;
                else now++;
            }
            was_copy[s[i] - 'a'] = now;
            need_copy[now - 'a'] = 1;
            t += now;
        }
    }
    return t;
}

void solve(int k, string s, string a, string b){
    for (int i = 0; i < 26; i++){
        was[i] = '#';
        need[i] = 0;
    }
    for (int i = 0; i < s.size(); i++){
        if (was[s[i] - 'a'] != '#'){
            if (a[i] < was[s[i] - 'a']) break;
            continue;
        }
        if (!need[a[i] - 'a']){
            was[s[i] - 'a'] = a[i];
            need[a[i] - 'a'] = 1;
            auto t = get(s, 'a' + k - 1, 1);
            if (t >= a){
                continue;
            }
            was[s[i] - 'a'] = '#';
            need[a[i] - 'a'] = 0;
        }
        for (char j = a[i] + 1; j <= 'z'; j++){
            if (!need[j - 'a']){
                was[s[i] - 'a'] = j;
                need[j - 'a'] = 1;
                break;
            }
        }
        break;
    }
    auto t = get(s, 'a', 0);
    if (a <= t && t <= b){
        cout << "YES\n";
        vector<char> show(k);
        vector<int> used(26);
        for (char i = 'a'; i <= 'a' + k - 1; i++){
            show[i - 'a'] = '#';
        }
        for (int i = 0; i < s.size(); i++){
            show[s[i] - 'a'] = t[i];
            used[t[i] - 'a'] = 1;
        }
        char now = 'a', noww = 'a';
        for (int i = 0; i < k; i++, now++) {
            if (show[now - 'a'] != '#') continue;
            while(used[noww - 'a']){
                noww++;
            }
            used[noww - 'a'] = 1;
            show[now - 'a'] = noww;
        }
        for (auto to : show){
            cout << to;
        }
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k;
        string s, a, b;
        cin >> k >>  s >> a >> b;
        solve(k, s, a, b);
    }
    return 0;
}