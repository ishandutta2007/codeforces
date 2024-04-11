#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

struct InType {
    int n;
    char c;
    string s;
};

std::istream& operator>>(std::istream& stream, InType& in) {
    return stream >> in.n >> in.c >> in.s;
}

struct OutType {
    vector<int> v;
};

std::ostream& operator<<(std::ostream& stream, const OutType& out) {
    stream << out.v.size() << '\n';
    copy(out.v.begin(), out.v.end(), ostream_iterator<int>{stream, " "});
    return stream;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<InType> inp(istream_iterator<InType>(cin), {});

    vector<OutType> output(t);
    transform(inp.begin(), inp.end(), output.begin(), [&](InType p) -> OutType {
        int n = p.n;
        int ch = p.c;
        string s = p.s;
        if (all_of(s.begin(), s.end(), [&](char c) { return c == ch; })) {
            return OutType{vector<int>{}};
        }
        int pos = find(s.begin() + n / 2, s.end(), ch) - s.begin();
        if (pos == n) {
            return OutType{vector<int>{n - 1, n}};
        } else {
            return OutType{vector<int>{pos + 1}};
        }
    });
    copy(output.begin(), output.end(), ostream_iterator<OutType>{cout, "\n"});
}