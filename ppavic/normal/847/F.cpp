#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

/*
5 4 3 2
1 1
*/

using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
const int N=105;

int n, k, m, a;
vector <ppi> v;
int cnt[N], zadnji[N], ind[N];

int cmp(ppi a, ppi b) {
    if (a.first.second==b.first.second) return a.second<b.second;
    return a.first.second>b.first.second;
}

int prvi(int pos) {
    int cnt1=0, ostalo_glasova=m-a;
    for (int i=0; cnt1<k; ++i) {
        if (v[i].first.first==pos) continue;
        cnt1++;
        if (v[i].first.second>cnt[pos]) continue;
        else if (v[i].first.second==cnt[pos]) {
            if (v[i].second<zadnji[pos]) continue;
            else {
                ostalo_glasova--;
                continue;
            }
        }
        else {
            ostalo_glasova-=cnt[pos]-v[i].first.second+1;
        }
    }
    return ostalo_glasova>=0;
}

int treci(int pos) {
    for (int i=0; i<k; ++i) {
        if (cnt[pos]+m-a>v[i].first.second) return 0;
    }
    return 1;
}

void load() {
    scanf("%d %d %d %d", &n, &k, &m, &a);
    for (int i=0; i<a; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        zadnji[x]=i+1;
    }
}

void solve() {
    if (k==n) {
        for (int i=1; i<=n; ++i) {
            if (cnt[i]==0 && m==a) printf("3 ");
            else if (cnt[i]==0) printf("2 ");
            else printf("1 ");
        }
        return;
    }
    for (int i=1; i<=n; ++i) {
        v.push_back(make_pair(make_pair(i, cnt[i]), zadnji[i]));
    }
    sort(v.begin(), v.end(), cmp);
    /*for (int i=0; i<n; ++i) {
        printf("Kand: %d, Num: %d, Last_vote: %d\n", v[i].first.first, v[i].first.second, v[i].second);
    }*/
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<v.size(); ++j) {
            if (v[j].first.first==i) {
                ind[i]=j;
                break;
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        if (!prvi(i) && cnt[i]!=0) {
            printf("1 ");
            continue;
        }
        if (treci(i)) {
            printf("3 ");
            continue;
        }
        printf("2 ");
    }
}

int main() {
    load();
    solve();
    return 0;
}