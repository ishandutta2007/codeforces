#include <bits/stdc++.h>

using namespace std;

// rmq_init egy vektort var
// ram_ask(kezd, veg, id) id=0 - minimum, id=1 - maximum
// part<int, int>-et ad vissza, azt is megmondja, hogy hol van

vector<vector<pair<int, int>>> rmq_mini, rmq_maxi;
vector<int> rmq_log;
void rmq_init(vector<int> sz) {
    int n=sz.size();
    rmq_log.resize(n+1);
    for (int i=2; i<=n; i++) {
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
pair<int, int> rmq_ask(int l, int r, int id) {
    int s=rmq_log[r-l+1], s2=r+1-(1<<s);
    if (!id) {
        return min(rmq_mini[s][l], rmq_mini[s][s2]);
    } else {
        return max(rmq_maxi[s][l], rmq_maxi[s][s2]);
    }
}


int n, m;
vector<int> sz;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    rmq_init(sz);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c, d, k;
        cin >> b >> a >> d >> c >> k;
        a--, c--;
        if (a>c) swap(a, c);
        int ert=rmq_ask(a, c, 1).first;
        cout << ((c-a)%k==0 && (d-b)%k==0 && ert<b+(m-b)/k*k ? "YES" : "NO") << "\n";
    }

    return 0;
}