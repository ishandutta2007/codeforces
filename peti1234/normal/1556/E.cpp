#include <bits/stdc++.h>

using namespace std;


vector<vector<pair<long long, int>>> rmq_mini, rmq_maxi;
vector<int> rmq_log;
void rmq_init(vector<long long> sz) {
    int n=sz.size();
    rmq_log.resize(n);
    for (int i=2; i<n; i++) {
        rmq_log[i]=rmq_log[i/2]+1;
    }
    int po=1, db=1;
    while (po<=n) {
        po*=2, db++;
    }
    rmq_mini.resize(db);
    rmq_maxi.resize(db);
    for (int i=0; i<db; i++) {
        rmq_mini[i].resize(n);
        rmq_maxi[i].resize(n);
    }
    for (int i=0; i<n; i++) {
        rmq_mini[0][i]={sz[i], i};
        rmq_maxi[0][i]={sz[i], i};
    }
    for (int j=1; j<db; j++) {
        for (int i=0; i+(1<<j)<=n; i++) {
            int s=i+(1<<(j-1));
            rmq_mini[j][i]=min(rmq_mini[j-1][i], rmq_mini[j-1][s]);
            rmq_maxi[j][i]=max(rmq_maxi[j-1][i], rmq_maxi[j-1][s]);
        }
    }
}
pair<long long, int> rmq_ask(int l, int r, int id) {
    int s=rmq_log[r-l+1], s2=r+1-(1<<s);
    if (!id) {
        return min(rmq_mini[s][l], rmq_mini[s][s2]);
    } else {
        return max(rmq_maxi[s][l], rmq_maxi[s][s2]);
    }
}





int n, q, l, r;
vector<long long> sz;


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    sz.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin >> sz[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz[i]=x-sz[i];
    }
    for (int i=1; i<=n; i++) {
        sz[i]+=sz[i-1];
    }
    rmq_init(sz);

    while (q--) {
        cin >> l >> r;
        long long val=sz[l-1];
        long long mini=rmq_ask(l, r, 0).first, maxi=rmq_ask(l, r, 1).first;
        if (val!=sz[r] || mini<val) {
            cout << -1 << "\n";
        } else {
            cout << maxi-val << "\n";
        }
    }
    return 0;
}