#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

struct moj {
    int pos, id;
    int ile;

    bool operator < (const moj & other) const {
        return pos < other.pos;
    }
};

struct ccc {
    int id, ile;
    int pos;


    bool operator < (const ccc & other) const {
        return pos < other.pos;
    }
};

struct trzy {
    int a, b, c;
};

vector<int> t;
vector<moj> s;

int pos[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        s.push_back({a, i, 0});
        pos[i] = a;
    }

    for (int a, i = 0; i < n; i++) {
        cin >> a;
        t.push_back(a);
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    vector<ccc> dod, uj;
    int suma = 0;
    for (int i = 0; i < s.size(); i++) {
            //cout << s[i].pos << " " << t[i]<< endl;
        s[i].ile = t[i] - s[i].pos;
        suma += s[i].ile;
        //cout << s[i].id << " " << s[i].pos << " " << s[i].ile << endl;
        if (s[i].ile > 0) {
            dod.push_back({s[i].id, s[i].ile, s[i].pos});
        } else if (s[i].ile < 0) {
            uj.push_back({s[i].id, s[i].ile, s[i].pos});
        }
    }/*
    cout << endl;
    for (ccc i : dod) {
        cout << i.id << " " << i.pos << " " << i.ile << endl;
    }

    cout << endl;

    for (ccc i : uj) {
        cout << i.id << " " << i.pos << " " << i.ile << endl;
    }

*/
    if (suma != 0) {
        cout << "NO";
        return 0;
    }


    //sort(dod.begin(), dod.end());
    //sort(uj.begin(), uj.end());

    vector<trzy> res;
    int it = 0;
    for (int i = 0; i < dod.size(); i++) {
        while (dod[i].ile) {
            //cout << it << " "  << uj[it].ile << endl;
            if (uj[it].ile == 0) it++;
            int d = min(abs(dod[i].ile), abs(uj[it].ile));
            if (pos[dod[i].id] >= pos[uj[it].id]) {
                cout << "NO";
                return 0;
            }
            pos[dod[i].id] += d;
            pos[uj[it].id] -= d;
            dod[i].ile -= d;
            uj[it].ile += d;
            res.push_back({dod[i].id, uj[it].id, d});
        }
    }

    /*while (!a.empty()) {
        ccc x = *a.begin(), y = *a.rbegin();
        a.erase(a.begin());
        auto it = a.end();
        it--;
        a.erase(it);
        int p = min(abs(x.ile), abs(y.ile));

        res.push_back({y.id, x.id, p});
        //cout << x.id << " " << y.id << " " << p << endl;
        x.ile += p;
        y.ile -= p;

        if (x.ile) {
            a.insert(x);
        }

        if (y.ile) {
            a.insert(y);
        }
    }*/

    cout << "YES\n";
    cout << res.size() << "\n";
    for (trzy i : res) {
        cout << i.a << " " << i.b << " " << i.c << "\n";
    }


    return 0;
}
/*

*/