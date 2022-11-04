#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <int> sos(1 << 9);
    while(n--) {
        int f;
        cin >> f;

        int conf = 0;
        while(f--) {
            int x;
            cin >> x;
            conf |= (1 << (x - 1));
        }

        sos[conf]++;
    }

    for(int bit = 0; bit < 9; bit++) {
        for(i = 0; i < (1 << 9); i++) {
            if(i & (1 << bit)) {
                sos[i] += sos[i ^ (1 << bit)];
            }
        }
    }

    vector < pair <int, int> > id(1 << 9);
    vector < pair <ll, ll> > price(1 << 9, {INT_MAX, INT_MAX});
    for(i = 1; i <= m; i++) {
        int f, c;
        cin >> c >> f;

        int conf = 0;
        while(f--) {
            int x;
            cin >> x;
            conf |= (1 << (x - 1));
        }

        if(price[conf].first > c) {
            price[conf].second = price[conf].first;
            id[conf].second = id[conf].first;
            price[conf].first = c;
            id[conf].first = i;
        }
        else if(price[conf].second > c) {
            price[conf].second = c;
            id[conf].second = i;
        }
    }

    int id1, id2, ans = -1, cst = INT_MAX;
    for(int a = 0; a < (1 << 9); a++) {
        if(id[a].first == 0) {
            continue;
        }
        for(int b = 0; b < (1 << 9); b++) {
            if(a != b && id[b].first && (sos[a | b] > ans || (sos[a | b] == ans && price[a].first + price[b].first < cst))) {
                ans = sos[a | b];
                cst = price[a].first + price[b].first;
                id1 = id[a].first, id2 = id[b].first;
            }
        }

        if(ans < sos[a] || (ans == sos[a] && price[a].first + price[a].second < cst)) {
            ans = sos[a];
            cst = price[a].first + price[a].second;
            id1 = id[a].first, id2 = id[a].second;
        }
    }

    if(id1 > id2) {
        swap(id1, id2);
    }

    cout << id1 << " " << id2;

    //cin.close();
    //cout.close();
    return 0;
}