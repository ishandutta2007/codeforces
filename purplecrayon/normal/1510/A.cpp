#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

struct S {
    int main_row = -1;
    vector<string> v;
    void init(string s) {
        v.clear();
        v.resize(3);
        int m = sz(s)+4;
        string border = string(m, '-');
        border[0] = '+', border[m-1] = '+';
        v[0] = border, v[2] = border;
        v[1] = "+ " + s + " +";
        main_row = 1;
    }
    void space_top(int x) {
        vector<string> u;
        int m = sz(v[0]);
        for (int i = 0; i < x; i++) u.push_back(string(m, ' '));
        for (auto s : v) u.push_back(s);

        main_row += x;
        v = u;
    }
    void space_bot(int x) {
        vector<string> u;
        int m = sz(v[0]);
        for (auto s : v) u.push_back(s);
        for (int i = 0; i < x; i++) u.push_back(string(m, ' '));
        v = u;
    }
    void space_left(int x) {
        for (auto& s : v) s = string(x, ' ') + s; 
    }
    void space_right(int x) {
        for (auto& s : v) s = s + string(x, ' ');
    }
    void plus() {
        space_left(3);
        space_right(3);
        space_bot(2);
        int m = sz(v[0]);
        v[main_row][0] = '+';
        v[main_row][1] = '-';
        v[main_row][2] = '>';
        v[main_row][m-1] = '+';
        v[main_row][m-2] = '>';
        v[main_row][m-3] = '-';
        int n = sz(v);
        for (int i = main_row+1; i < n-1; i++) {
            v[i][0] = v[i][m-1] = '|';
        }
        v[n-1][0] = v[n-1][m-1] = '+';
        v[n-1][1] = '<';
        for (int i = 2; i < m-1; i++) v[n-1][i] = '-';
    }
    void ques() {
        space_top(2);
        space_left(3);
        space_right(3);

        int m = sz(v[0]);
        v[main_row][0] = '+';
        v[main_row][1] = '-';
        v[main_row][2] = '>';

        v[main_row][m-1] = '+';
        v[main_row][m-2] = '>';
        v[main_row][m-3] = '-';
        for (int i = 1; i < main_row; i++) {
            v[i][0] = v[i][m-1] = '|';
        }
        v[0][0] = v[0][m-1] = '+';
        v[0][m-2] = '>';
        for (int i = 1; i < m-2; i++) v[0][i] = '-';
        main_row = 0;

        space_top(1);
    }
    void star() {
        space_left(3), space_right(3);
        space_top(2), space_bot(2);

        int n = sz(v), m = sz(v[0]);

        for (int i = 0; i < m; i++) v[0][i] = v[n-1][i] = '-';
        for (int i = 0; i < n; i++) v[i][0] = v[i][m-1] = '|';

        v[0][0] = v[0][m-1] = v[n-1][0] = v[n-1][m-1] = '+';
        v[0][m-2] = '>', v[n-1][1] = '<';

        v[main_row][0] = '+', v[main_row][1] = '-', v[main_row][2] = '>';
        v[main_row][m-1] = '+', v[main_row][m-2] = '>', v[main_row][m-3] = '-';

        main_row = 0;

        space_top(1);
    }
    void apply(char c) {
        if (c == '+') plus();
        if (c == '*') star();
        if (c == '?') ques();
    }
    void add_ends() {
        space_left(3), space_right(3);
        int m = sz(v[0]);
        v[main_row][0] = 'S', v[main_row][1] = '-', v[main_row][2] = '>';
        v[main_row][m-3] = '-', v[main_row][m-2] = '>', v[main_row][m-1] = 'F';
    }
    void print() {
        int n = sz(v), m = sz(v[0]);
        cout << n << ' ' << m << '\n';
        for (auto s : v) {
            assert(sz(s) == m);
            cout << s << '\n';
        }
    }
};

S concat(S a, S b) {
    bool has_swap = 0;
    if (a.main_row > b.main_row) swap(a, b), has_swap ^= 1;
    a.space_top(b.main_row-a.main_row);

    int a_n = sz(a.v), b_n = sz(b.v);

    if (a_n > b_n) swap(a, b), swap(a_n, b_n), has_swap ^= 1;
    a.space_bot(b_n-a_n);


    if (has_swap) swap(a, b);

    assert(a.main_row == b.main_row);

    int n = sz(a.v);
    assert(n == sz(b.v));

    S ans; ans.v.resize(n);
    ans.main_row = a.main_row;
    for (int i = 0; i < n; i++) {
        string join = "  ";
        if (i == ans.main_row) join = "->";
        ans.v[i] = a.v[i]+join+b.v[i];
    }
    return ans;
}
bool is_op(char c) {
    if ('A' <= c && c <= 'Z') return 0;
    if (c == '(' || c == ')') return 0;
    return 1;
}
bool is_alp(char c) {
    if ('A' <= c && c <= 'Z') return 1;
    return 0;
}
S parse_no_ops(string s) {
    vector<S> split;

    string bld = "";

    auto add = [&]() {
        if (!sz(bld)) return;
        S cur; cur.init(bld);
        split.push_back(cur);
        bld = "";
    };
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '(' || s[i] == ')') add();
        else {
            assert(is_alp(s[i]));
            bld += s[i];
        }
    }
    add();
    S ans = split[0];
    for (int i = 1; i < sz(split); i++) ans = concat(ans, split[i]);
    return ans;

}
S parse_string(string s) { //no |'s
    bool bad = 0;
    for (char c : s) if (is_op(c)) bad = 1;
    if (!bad) {
        return parse_no_ops(s);
    }

    vector<int> match(sz(s), -1);
    for (int i = 0; i < sz(s); i++) if (s[i] == '(') {
        int bal = 0;
        for (int j = i; j < sz(s); j++) {
            if (s[j] == ')' || s[j] == '(')
                bal += (s[j] == '(' ? 1 : -1);
            if (bal == 0) {
                match[i] = j;
                match[j] = i;
                break;
            }
        }
    }

    vector<S> tokens;


    vector<bool> mark(sz(s));
    for (int i = 0; i < sz(s); i++) {
        if (!is_op(s[i]) && !is_alp(s[i])) mark[i] = 1;
    }

    auto get = [&](int l, int r) {
        for (int i = l; i <= r; i++) mark[i] = 1;
        return parse_string(s.substr(l, r-l+1));
    };

    for (int i = sz(s)-1; i >= 0; i--) if (!mark[i]) {
        if (is_op(s[i]) && !is_op(s[i-1])) {
            int l = i-1;
            if (s[i-1] == ')') {
                l = match[i-1];
            }
            S cur = get(l, i-1);
            for (int j = i; j < sz(s) && is_op(s[j]); j++) {
                cur.apply(s[j]);
            }
            tokens.push_back(cur);

        } else if (!is_op(s[i])) {
            string t="";

            int j = i;
            for (; j >= 0 && is_alp(s[j]); j--);
            j++;

            S cur = get(j, i);
            tokens.push_back(cur);
        }
    }
    reverse(tokens.begin(), tokens.end());

    S ans = tokens[0];
    for (int i = 1; i < sz(tokens); i++) ans = concat(ans, tokens[i]);

    return ans;
}
S or_all(vector<S> token) {
    if (sz(token) == 1) return token[0];

    int m = 0;
    for (auto c : token) {
        m = max(m, sz(c.v[0]));
    }
    for (auto& c : token) {
        int old = sz(c.v[0]);
        c.space_right(m-old);
        assert(sz(c.v[0]) == m);
        for (int i = old; i < m; i++) {
            c.v[c.main_row][i] = '-';
        }

        c.space_left(3); c.space_right(3);
    }
    S ans = token[0];
    vector<int> main_rows{ans.main_row};
    for (int i = 1; i < sz(token); i++) {
        ans.space_bot(1);
        main_rows.push_back(token[i].main_row + sz(ans.v));
        for (auto r : token[i].v) ans.v.push_back(r);
    }

    m = sz(ans.v[0]);
    for (int i = main_rows[0]; i <= main_rows.back(); i++) {
        ans.v[i][0] = ans.v[i][m-1] = '|';
    }
    for (int i : main_rows) {
        ans.v[i][0] = '+', ans.v[i][1] = '-', ans.v[i][2] = '>';
        ans.v[i][m-1] = '+', ans.v[i][m-2] = '>', ans.v[i][m-3] = '-';
    }
    return ans;
}
S parse(string s) {
    if (s.find('|') == string::npos) {
        return parse_string(s);
    }

    vector<S> token;

    int bal = 0;
    string t="";
    for (char c : s) {
        if (c == '(') bal++;
        if (c == ')') bal--;

        if (c == '|' && bal == 0) {
            token.push_back(parse(t));
            t = "";
        } else {
            t += c;
        }
    }
    if (t == s) {
        if (s[0] != '(') {
            for (int i = 1; i < sz(s); i++) if (s[i] == '(') {
                return concat(parse(s.substr(0, i)), parse(s.substr(i, sz(s)-i)));
            }
        }
        int bal = 0;
        for (int i = 0; i < sz(s)-1; i++) {
            char c = s[i];
            if (c == '(') bal++;
            if (c == ')') bal--;
            if (bal == 0) {
                bool bad = 1;
                for (int j = i+1; j < sz(s); j++) if (!is_op(s[j])) bad = 0;
                if (bad) {
                    S ans = parse(s.substr(0, i+1));
                    for (int j = i+1; j < sz(s); j++) ans.apply(s[j]);
                    return ans;
                }

                while (is_op(s[i+1])) i++;
                return concat(parse(s.substr(0, i+1)), parse(s.substr(i+1, sz(s)-i-1)));
            }
        }
        assert(s[0] == '(');
        assert(s[sz(s)-1] == ')');
        s.erase(s.begin()); s.pop_back();
        return parse(s);
    }
    if (sz(t)) {
        token.push_back(parse(t));
        t = "";
    }

    return or_all(token);
}
void solve(){
    string s; cin >> s;
    S ans = parse(s);
    ans.add_ends();
    ans.print();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}