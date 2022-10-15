//lol

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define F first
#define S second

int n;
ll a[101010];
ll b[101010];
vector<pair<ll,ll>> v;
ll d[101010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    v.push_back({0,b[1]});
    int k = 0;
    for (int i = 2; i <= n; i++) {
        while (k+1 < v.size() &&
            v[k].F+v[k].S*a[i] > v[k+1].F+v[k+1].S*a[i]) {
            k++;
        }
        d[i] = v[k].F+v[k].S*a[i];
        while (v.size() >= 2) {
            int u = v.size();
            double x1 = (double)(v[u-1].F-d[i])/(b[i]-v[u-1].S);
            double x2 = (double)(v[u-1].F-v[u-2].F)/(v[u-2].S-v[u-1].S);
            if (x2 > x1) v.pop_back();
            else break;
        }
        if (v.back().S > b[i]) v.push_back({d[i],b[i]});
    }
    cout << d[n] << "\n";
}