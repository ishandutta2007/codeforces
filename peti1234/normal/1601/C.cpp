#include <bits/stdc++.h>

using namespace std;
const int c=1000005, c2=1<<21;
int w, n, m, ert, sum[c2], mini[c2], kezd[c2], veg[c2];
vector<pair<int, int> > sz;
long long ans, inv;


int init(int ert) {
    int po=1;
    while (po<=ert) po*=2;
    for (int i=1; i<2*po; i++) mini[i]=0, sum[i]=0;
    for (int i=po; i<2*po; i++) kezd[i]=veg[i]=i-po+1;
    for (int i=po-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
}
int s(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) return 0;
    if (l<=kezd[a] && veg[a]<=r) return 2;
    return 1;
}
void add(int a, int l, int r, int ert) {
    int p=s(a, l, r);
    if (!p) return;
    if (p==2) sum[a]+=ert, mini[a]+=ert;
    if (p==1) {
        add(2*a, l, r, ert);
        add(2*a+1, l, r, ert);
        mini[a]=min(mini[2*a], mini[2*a+1])+sum[a];
    }
}
int ask(int a, int l, int r) {
    int p=s(a, l, r);
    if (!p) return 2*c;
    if (p==2) {
        return mini[a];
    }
    if (p==1) {
        return min(ask(2*a, l, r), ask(2*a+1, l, r))+sum[a];
    }
}

void add(int pos, int ert) {
    add(1, pos, n+1, ert);
}
int ask(int l, int r) {
    return ask(1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        init(n+1);
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back({x, -i});
            sz.push_back({x, i});
            add(i+1, 1);
        }
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            sz.push_back({x, 0});
        }
        sort(sz.begin(), sz.end());
        int pos=1;
        for (auto x:sz) {
            int se=x.second;
            if (se<0) {
                add(-se+1, -1);
            }
            if (se>0) {
                inv+=ask(se, se);
                add(1, 1);
                add(se+1, -1);
            }
            if (se==0) {
                ans+=ask(1, n+1);
            }
        }
        cout << ans+inv/2 << "\n";
        ans=0, inv=0, sz.clear();
    }
    return 0;
}