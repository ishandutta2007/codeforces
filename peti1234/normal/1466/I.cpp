#include <bits/stdc++.h>

using namespace std;
int n, b;
bool ask(int a, string s) {
    cout.flush() << a << " " << s << "\n";
    string v;
    cin >> v;
    return (v[0]=='y');
}
void tele(string &s) {
    while (s.size()<b) {
        s+="1";
    }
}
void solve(vector<int> sz, string s) {
    if (s.size()==b) {
        cout << 0 << " " << s << "\n";
        return;
    }
    stack<pair<int, string> > p;
    p.push({0, s});

    for (int id:sz) {
        while (p.size()>1) {
            string ut=p.top().second;
            tele(ut);
            if (ask(id, ut)) {
                p.pop();
            } else {
                break;
            }
        }
        string ut=p.top().second, uj=ut;
        if (ut.size()==b) {
            continue;
        }
        ut+="0";
        tele(ut);
        if (ask(id, ut)) {
            uj+="1";
        } else {
            uj+="0";
        }
        p.push({id, uj});
    }

    vector<int> uj;
    string kov=p.top().second;

    while (p.size()>1) {
        auto t=p.top();
        p.pop();
        string k=kov;
        tele(k);
        if (ask(t.first, k)) {
            kov=t.second;
            uj.clear();
        }
        uj.push_back(t.first);
    }
    solve(uj, kov);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    vector<int> sz;
    for (int i=1; i<=n; i++) {
        sz.push_back(i);
    }
    solve(sz, "");
    return 0;
}