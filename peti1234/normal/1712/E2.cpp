#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long db[c], fen[c], res[c], o;

int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<c) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
long long ask(int a) {
    long long ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    vector<pair<pair<int, int>, int> > sz;
    for (int i=1; i<=w; i++) {
        int l, r;
        cin >> l >> r;
        sz.push_back({{-l, r}, i});
    }
    sort(sz.begin(), sz.end());
    int ut=c;
    for (auto x:sz) {
        long long l=-x.first.first, r=x.first.second, id=x.second;
        while (ut>l) {
            ut--;
            for (int i=2*ut; i<c; i+=ut) {
                add(i, db[i]);
                db[i]++;
            }
        }
        long long len=(r-l+1), ans=len*(len-1)*(len-2)/6;
        ans-=ask(r);
        ans-=max(o, r/6-(l-1)/3);
        ans-=max(o, r/15-(l-1)/6);

        res[id]=ans;
    }
    for (int i=1; i<=w; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}
/*
1
6 86868
*/