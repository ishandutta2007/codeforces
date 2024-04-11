#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

string make(string s, string t){
    vector<bool> used(200);
    string k = "";
    for (int i = 0; i < t.size() + 1; i++){
        for (int j = 0; j < s.size(); j++){
            if (!used[s[j]]){
                k += s[j];
            }
        }
        if (i < t.size()) used[t[i]] = 1;
    }
    return k;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        set<int> st;
        map<int,int> cnt;
        string del = "";
        for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
        for (int i = 0; i < s.size(); i++) st.insert(s[i]);
        int now = st.size(), need = st.size();
        bool x = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (st.find(s[i]) == st.end()) continue;
            if (cnt[s[i]] % now != 0){
                x = 1;
            }
            else{
                st.erase(s[i]);
                cnt[s[i]] /= now;
                now--;
                del += s[i];
            }
        }
        reverse(del.begin(), del.end());
        if (x){
            cout << -1 << endl;
            continue;
        }
        string kek = "";
        for (int i = 0; i < s.size(); i++){
            kek += s[i];
            cnt[s[i]]--;
            if (cnt[s[i]] == 0) need--;
            if (need == 0) break;
        }
        if (make(kek, del) != s){
            cout << -1 << endl;
        }
        else{
            cout << kek << ' ' << del << endl;
        }
    }
    return 0;
}