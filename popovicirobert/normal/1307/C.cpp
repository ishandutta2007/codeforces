#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    vector <int> fr(26);
    vector < vector <ll> > cnt(26, vector <ll>(26));

    ll ans = 0;
    for(auto &it : str) {
        it -= 'a';
        for(i = 0; i < 26; i++) {
            cnt[i][it] += fr[i];
        }
        fr[it]++;
    }

    for(i = 0; i < 26; i++) {
        ans = max(ans, 1LL * fr[i]);
        for(int j = 0; j < 26; j++) {
            ans = max(ans, cnt[i][j]);
        }
    }

    cout << ans;

    return 0;
}