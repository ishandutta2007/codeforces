#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

using namespace std;

typedef long long ll;

mt19937 rnd(228);

unordered_set<string> kw;
vector<string> tokens;
unordered_map<string, string> n2n;
int mkw = 0;

string transformName(string const& s) {
    static string cname = "";
    if (!n2n.count(s)) {
        while (true) {
            bool w = 1;
            for (int i = sz(cname) - 1; i >= 0; --i) {
                if (cname[i] == 'z') {
                    cname[i] = 'a';
                    w = 1;
                } else {
                    ++cname[i];
                    w = 0;
                    break;
                }
            }
            if (w)
                cname += 'a';
            if (!kw.count(cname))
                break;
        }
        n2n[s] = cname;
    }
    return n2n[s];
}

bool isWC(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '$' || ('0' <= c && c <= '9');
}

void parse(string const& s) {
    int n = 0;
    while (s[n] != '#' && s[n] != '\0')
        ++n;
    int i = 0;
    while (1) {
        while (s[i] == ' ')
            ++i;
        if (i == n)
            break;
        int klen = 0;
        for (int j = min(mkw, n - i); j > 0; --j)
            if (kw.count(s.substr(i, j))) {
                klen = j;
                break;
            }
        if (s[i] >= '0' && s[i] <= '9') {
            int j = i + 1;
            while (s[j] >= '0' && s[j] <= '9')
                ++j;
            if (klen >= j - i)
                j = i + klen;
            tokens.push_back(s.substr(i, j - i));
            i = j;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_' || s[i] == '$') {
            int j = i + 1;
            while ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9') || s[j] == '_' || s[j] == '$')
                ++j;
            if (klen >= j - i) {
                j = i + klen;
                tokens.push_back(s.substr(i, j - i));
            } else {
                tokens.push_back(transformName(s.substr(i, j - i)));
            }
            i = j;
        } else {
            assert(klen);
            tokens.push_back(s.substr(i, klen));
            i += klen;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
#ifdef ONPC
    freopen("j.in", "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string k;
        cin >> k;
        kw.insert(k);
        mkw = max(mkw, sz(k));
    }

    int ls;
    cin >> ls;
    while (1) {
        string s;
        if (getline(cin, s))
            parse(s);
        else
            break;
    }

    int i = 0;
    int nxt = sz(tokens);
    while (i < sz(tokens)) {
        if (nxt == i) {
            cout << " ";
            nxt = sz(tokens);
        }
        bool isW = 1, isN = 1;
        for (char c : tokens[i])
            if (c < '0' || c > '9')
                isN = 0;
        for (char c : tokens[i])
            if (!isWC(c))
                isW = 0;
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9')
            isW = 0;

        bool done = 0;
        string ss = tokens[i];
        for (int x = i + 1; !done && x < nxt; ++x) {
            for (char c : tokens[x]) {
                ss += c;
                if ('0' > c || '9' < c)
                    isN = 0;
                if (!isWC(c))
                    isW = 0;
                if (sz(ss) > mkw && !isN && !isW) {
                    done = 1;
                    break;
                }
                if (kw.count(ss) || isN || isW) {
                    done = 1;
                    nxt = x;
                    break;
                }
            }
        }

        cout << tokens[i];
        i++;
    }
    cout << "\n";
}