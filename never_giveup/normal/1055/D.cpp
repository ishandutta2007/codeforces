#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const int maxn = 3e3 + 10, inf = 1e9 + 100;

vector<int> prefix(string s){
    vector<int> p(s.size());
    int k = 0;
    for (int i = 1; i < s.size(); i++){
        while (k > 0 && s[k] != s[i])
            k = p[k - 1];
        if (s[k] == s[i])
            k++;
        p[i] = k;
    }
    return p;
}

string a[maxn], b[maxn];

pair<int, int> seg[maxn];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++){
        int l = -1, r;
        for (int j = 0; j < a[i].size(); j++)
        if (a[i][j] != b[i][j]){
            if (l == -1)
                l = j;
            r = j;
        }
        seg[i].fr = l;
        seg[i].sc = r;
    }
    string s, t;
    while (1){
        int o = -1;
        for (int i = 0; i < n; i++)
        if (seg[i].fr != -1)
            if (seg[i].fr == 0){
                o = -1;
                break;
            } else {
                if (o == -1)
                    o = a[i][seg[i].fr - 1];
                if (o != a[i][seg[i].fr - 1]){
                    o = -1;
                    break;
                }
            }
        if (o == -1)
            break;
        for (int i = 0; i < n; i++)
        if (seg[i].fr != -1)
            seg[i].fr--;
    }
    while (1){
        int o = -1;
        for (int i = 0; i < n; i++)
        if (seg[i].fr != -1)
            if (seg[i].sc == a[i].size() - 1){
                o = -1;
                break;
            } else {
                if (o == -1)
                    o = a[i][seg[i].sc + 1];
                if (o != a[i][seg[i].sc + 1]){
                    o = -1;
                    break;
                }
            }
        if (o == -1)
            break;
        for (int i = 0; i < n; i++)
        if (seg[i].fr != -1)
            seg[i].sc++;
    }
    for (int i = 0; i < n; i++)
    if (seg[i].fr != -1){
        for (int j = seg[i].fr; j <= seg[i].sc; j++)
            s.push_back(a[i][j]),
            t.push_back(b[i][j]);
        break;
    }
    for (int i = 0; i < n; i++){
        int l = seg[i].fr, r = seg[i].sc;
        auto q = prefix(s + '#' + a[i]);
        if (l == -1){
            for (int j = 0; j < q.size(); j++)
            if (q[j] == s.size()){
                cout << "NO";
                return 0;
            }
        } else {
            if (r - l + 1 != s.size()){
                cout << "NO";
                return 0;
            }
            for (int j = 0; j < q.size(); j++)
            if (q[j] == s.size()){
                if (s.size() + 1 + r != j){
                    cout << "NO";
                    return 0;
                }
                break;
            }
            if (q[s.size() + 1 + r] != s.size()){
                cout << "NO";
                return 0;
            }
            for (int j = l; j <= r; j++)
            if (b[i][j] != t[j - l]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n" << s << '\n' << t;
}