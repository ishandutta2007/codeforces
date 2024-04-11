#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 5;

int l[MAXN + 1], r[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    double ans = 0;
    for(int id = 0; id < n; id++) {
        for(int bid = l[id]; bid <= r[id]; bid++) {
            for(int conf = 0; conf < (1 << n); conf++) {
                bool ok = 1;
                double cur = 1.0;
                if(lsb(conf) != (1 << id))
                    continue;
                if((conf & (1 << id)) && conf != (1 << id)) {
                    for(i = 0; i < n; i++) {
                        if(conf & (1 << i)) {
                            if(l[i] > bid || r[i] < bid) {
                                ok = 0;
                            }
                            else {
                                cur *= 1.0 / (r[i] - l[i] + 1);
                            }
                        }
                        else {
                            if(l[i] >= bid) {
                                ok = 0;
                            }
                            else {
                                cur *= min(1.0 * (bid - l[i]) / (r[i] - l[i] + 1), 1.0);
                            }
                        }
                    }
                    if(ok == 1) {
                        ans += 1.0 * cur * bid;
                    }
                }
            }
            for(int win = 0; win < n; win++) {
                if(win == id || r[win] <= bid) {
                    continue;
                }
                for(int conf = 0; conf < (1 << n); conf++) {
                    double cur = min(1.0 * (r[win] - bid) / (r[win] - l[win] + 1), 1.0);
                    bool ok = 1;
                    if((conf & (1 << win)) || (conf & (1 << id)) == 0 || lsb(conf) != (1 << id)) {
                        continue;
                    }
                    for(i = 0; i < n; i++) {
                        if(i == win)
                            continue;
                        if(conf & (1 << i)) {
                            if(l[i] > bid || r[i] < bid) {
                                ok = 0;
                            }
                            else {
                                cur *= 1.0 / (r[i] - l[i] + 1);
                            }
                        }
                        else {
                            if(l[i] >= bid) {
                                ok = 0;
                            }
                            else {
                                cur *= min(1.0 * (bid - l[i]) / (r[i] - l[i] + 1), 1.0);
                            }
                        }
                    }
                    if(ok == 1) {
                            //printf("%d %d %d %d %f\n" ,id,bid,win,conf,cur);
                        ans += 1.0 * cur * bid;
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}