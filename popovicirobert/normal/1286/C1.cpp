#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

inline multiset <string> ask(int l, int r) {
    if(l > r) return multiset<string>();
    cout << "? " << l << " " << r << endl;
    multiset <string> ans;
    for(int i = l; i <= r; i++) {
        for(int j = i; j <= r; j++) {
            string cur;
            cin >> cur;
            sort(cur.begin(), cur.end());
            ans.insert(cur);
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    int i, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    cin >> n;

    multiset <string> a = ask(1, n);
    multiset <string> b = ask(2, n);

    for(auto &it : b) {
        a.erase(a.find(it));
    }

    vector <string> str;
    for(auto &it : a) {
        str.push_back(it);
    }
    sort(str.begin(), str.end(), [&](const string &a, const string &b) {
                return a.size() < b.size();
         });

    string sol;
    vector <int> fr(26);
    for(auto &it : str) {
        vector <int> cur(26);
        for(auto ch : it) {
            cur[ch - 'a']++;
        }
        for(i = 0; i < 26; i++) {
            if(cur[i] > fr[i]) {
                sol.push_back(i + 'a');
                break;
            }
        }
        fr = cur;
    }

    cout << "! " << sol << endl;

    return 0;
}