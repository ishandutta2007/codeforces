#include <bits/stdc++.h>

using namespace std;
const int c=1<<18;
int n, k, t[c], q, ut;
vector<int> sz[c], fen[c];
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<=n) {
        fen[a].push_back(b);
        a+=lsb(a);
    }
}
int ask(int l, int r) {
    int s=l, ans=0;
    while (s) {
        int si=fen[s].size(), aa, bb;
        int lo=-1, hi=si, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (fen[s][mid]<l) lo=mid;
            else hi=mid;
        }
        aa=hi;
        lo=-1, hi=si, mid=0;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (fen[s][mid]<=r) lo=mid;
            else hi=mid;
        }
        bb=hi;
        ans+=bb-aa;

        s-=lsb(s);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz[t[i]].push_back(i);
        int si=sz[t[i]].size();
        int kezd=(si<=k ? 1 : sz[t[i]][si-k-1]+1);
        //cout << "fontos " << i << " " << kezd << "\n";
        add(kezd, i);
    }
    for (int i=1; i<=n; i++) {
        sort(fen[i].begin(), fen[i].end());
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l=(l+ut)%n+1, r=(r+ut)%n+1;
        if (l>r) swap(l, r);
        //cout << "kerdes " << l << " " << r << "\n";
        ut=ask(l, r);
        cout << ut << "\n";
    }
    return 0;
}