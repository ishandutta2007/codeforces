#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

struct Data {
    int val;
    int l, r;
    bool operator <(const Data &other) const {
          if(val == other.val)
              return l < other.l;
          return val > other.val;
    }
};

multiset <Data> mst;
multiset <Data> :: iterator it;

struct Data1 {
    int val;
    int l, r;
    bool operator <(const Data1 &other) const {
        return l < other.l;
    }
    bool operator ==(const Data1 &other) const {
        return l == other.l && r == other.r;
    }
};

multiset <Data1> aux;
multiset <Data1> :: iterator it1, it2;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    i = 1;
    while(i <= n) {
        int j = i;
        while(j <= n && v[i] == v[j]) {
            j++;
        }
        mst.insert({j - i, i, j - 1});
        aux.insert({j - i, i, j - 1});
        i = j;
    }
    int ans = 0;
    while(!mst.empty()) {
        ans++;
        it = mst.begin();
        int l = it -> l, r = it -> r, val = it -> val;
        mst.erase(it);
        it1 = it2 = aux.find({val, l, r});
        if(it1 != aux.begin()) {
            it1--;
            it2++;
            if(it2 != aux.end() && v[it1 -> l] == v[it2 -> l]) {
                int left = it1 -> l, val1 = it1 -> val;
                int right = it2 -> r, val2 = it2 -> val;
                mst.erase(mst.find({it1 -> val, it1 -> l, it1 -> r}));
                mst.erase(mst.find({it2 -> val, it2 -> l, it2 -> r}));
                it2++;
                aux.erase(it1, it2);
                mst.insert({val1 + val2, left, right});
                aux.insert({val1 + val2, left, right});
            }
            else {
                aux.erase(aux.find({val, l, r}));
            }
        }
        else {
            aux.erase(aux.find({val, l, r}));
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}