#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ll inf = 1e9 + 7;

void checkmin(ll &a, ll b) {
    if (b < a) a = b;
}

ld getsum(vector<ld> &a, ll l, ll r, ld add) {
    return a[r] - a[l] + add;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ld T;
    cin >> n >> T;
    vector<pair<ld, ld>> inp(n);
    for (auto &i : inp) cin >> i.second;
    for (auto &i : inp) cin >> i.first;
    sort(inp.begin(), inp.end());
    if (inp[0].first > T || inp[n - 1].first < T) {
        cout << 0;
        return 0;
    }
    vector<ld> prefa(n), preft(n);
    ld summa = 0, summt = 0;
    for (int i = 0; i < n; ++i) {
        summa += inp[i].second;
        summt += inp[i].first * inp[i].second;
        prefa[i] = summa;
        preft[i] = summt;
    }
    ld midt = summt / summa;
    int l = 0, r = n - 1;
    while (abs(midt - T) > 1e-12) {
        if (midt > T) {
            ld allsumt = getsum(preft, l, r - 1, inp[l].first * inp[l].second);
            ld allsuma = getsum(prefa, l, r - 1, inp[l].second);
            if (abs(allsumt / allsuma - T) < 1e-12) {
                cout << allsuma;
                //system("pause");
                return 0;
            }
            if (allsumt / allsuma > T) {
                --r;
                midt = getsum(preft, l, r, inp[l].first * inp[l].second) / getsum(prefa, l, r, inp[l].second);
            } else {
                ld left = 0, right = inp[r].second;     
                while (true) {
                    ld m = (left + right) / 2;
                    if (abs((allsumt + inp[r].first * m) / (allsuma + m) - T) < 1e-12) {
                        right = m;
                        break;
                    }
                    if ((allsumt + inp[r].first * m) / (allsuma + m) < T) left = m;
                    else right = m;
                }
                cout << fixed << setprecision(20) << allsuma + right;
                //system("pause");
                return 0;
            } 
        } else {
            ld allsumt = getsum(preft, l + 1, r, inp[l + 1].first * inp[l + 1].second);
            ld allsuma = getsum(prefa, l + 1, r, inp[l + 1].second);
            if (abs(allsumt / allsuma - T) < 1e-12) {
                cout << allsuma;
                //system("pause");
                return 0;
            }
            if (allsumt / allsuma < T) {
                ++l;
                midt = getsum(preft, l, r, inp[l].first * inp[l].second) / getsum(prefa, l, r, inp[l].second);
            } else {
                ld left = 0, right = inp[l].second;
                while (true) {
                    ld m = (left + right) / 2;
                    if (abs((allsumt + inp[l].first * m) / (allsuma + m) - T) < 1e-12) {
                        right = m;
                        break;
                    }
                    if ((allsumt + inp[l].first * m) / (allsuma + m) > T) left = m;
                    else right = m;
                }
                cout << fixed << setprecision(20) << allsuma + right;
                //system("pause");
                return 0;
            } 
        }
    }
    cout << getsum(prefa, l, r, inp[l].second);
    //system("pause");
    return 0;
}