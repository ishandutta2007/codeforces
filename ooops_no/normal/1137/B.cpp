#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

vector<int> pref(string s){
    vector<int> pr(s.size());
    for (int i = 1; i < s.size(); i++){
        int j = pr[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pr[j - 1];
        }
        if (s[i] == s[j]) j++;
        pr[i] = j;
    }
    return pr;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    vector<int> a = pref(t);
    vector<int> col(2);
    for (int i = 0; i < s.size(); i++){
        col[s[i] - '0']++;
    }
    for (auto to : t){
        col[to - '0']--;
    }
    if (min(col[0], col[1]) < 0){
        cout << s << endl;
    }
    else{
        cout << t;
        while(1){
            vector<int> coll = col;
            for (int i = a.back(); i < t.size(); i++){
                coll[t[i] - '0']--;
            }
            if (min(coll[0], coll[1]) < 0){
                for (int i = 0; i < col[0]; i++) cout << 0;
                for (int i = 0; i < col[1]; i++) cout << 1;
                return 0;
            }
            for (int i = a.back(); i < t.size(); i++){
                cout << t[i];
            }
            col = coll;
        }
    }
    return 0;
}