#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

string make(string s, string a, string b){
    for (int i = 0; i + a.size() <= s.size(); i++){
        if (s.substr(i, a.size()) == a){
            for (int j = i; j < i + a.size(); j++){
                s[j] = b[j - i];
            }
            break;
        }
    }
    return s;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    vector<int> leftt(n), rightt(n, -1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    set<pair<string, string>> st;
    for (int i = 0; i < n; i++){
        if (a[i] == b[i]) continue;
        rightt[i] = a[i].size() - 1;
        while(a[i][leftt[i]] == b[i][leftt[i]]){
            leftt[i]++;
        }
        while(a[i][rightt[i]] == b[i][rightt[i]]){
            rightt[i]--;
        }
        st.insert({a[i].substr(leftt[i], rightt[i] - leftt[i] + 1), b[i].substr(leftt[i], rightt[i] - leftt[i] + 1)});
    }
    if (st.size() > 1){
        cout << "NO" << endl;
    }
    else{
        string s = st.begin()->first, t = st.begin()->second;
        while(1){
            set<char> setik;
            bool x = 1;
            for (int j = 0; j < n; j++){
                if (rightt[j] == -1) continue;
                if (leftt[j] == 0) {
                    x = 0;
                    break;
                }
                leftt[j]--;
                setik.insert(a[j][leftt[j]]);
            }
            if (setik.size() == 1 && x){
                s = *setik.begin() + s;
                t = *setik.begin() + t;
            }
            else break;
        }
        while(1){
            set<char> setik;
            bool x = 1;
            for (int j = 0; j < n; j++){
                if (rightt[j] == -1) continue;
                if (rightt[j] + 1 == a[j].size()) {
                    x = 0;
                    break;
                }
                rightt[j]++;
                setik.insert(a[j][rightt[j]]);
            }
            if (setik.size() == 1 && x){
                s += *setik.begin();
                t += *setik.begin();
            }
            else break;
        }
        bool x = 0;
        for (int i = 0; i < n; i++){
            if (make(a[i], s, t) != b[i]){
                x = 1;
            }
        }
        if (x) cout << "NO\n";
        else cout << "YES\n" << s << endl << t << endl;
    }
    return 0;
}