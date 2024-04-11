#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 6

using namespace std;

const int MAXN = (int) 2e5;

struct Data {
    int a, t;
    int pos;
    bool operator <(const Data &other) const {
        if(a == other.a)
            return t < other.t;
        return a > other.a;
    }
}v[MAXN + 1];

struct Data1 {
    int pos;
    bool operator <(const Data1 &other) const {
         return v[pos].t < v[other.pos].t;
    }
};

multiset <Data1> mst;
multiset <Data1> :: iterator it;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, t;
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for(i = 1; i <= n; i++) {
        cin >> v[i].a >> v[i].t;
        v[i].pos = i;
    }
    sort(v + 1, v + n + 1);
    pair <int, int> ans = {0, 0};
    int p = 1;
    ll sum = 0;
    for(i = n; i >= 0; i--) {
        while(mst.size() > i) {
            it = mst.end();
            it--;
            sum -= v[it -> pos].t;
            mst.erase(it);
        }
        while(p <= n && v[p].a >= i) {
            if(mst.size() < i) {
                mst.insert({p});
                sum += v[p].t;
            }
            else {
                it = mst.end();
                it--;
                if(v[it -> pos].t > v[p].t) {
                    sum -= v[it -> pos].t;
                    mst.erase(it);
                    mst.insert({p});
                    sum += v[p].t;
                }
            }
            p++;
        }
        if(mst.size() == i && sum <= t) {
            cout << i << endl;
            cout << i << endl;
            for(it = mst.begin(); it != mst.end(); it++)
                cout << v[it -> pos].pos << " ";
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}