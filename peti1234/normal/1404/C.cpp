#include <bits/stdc++.h>
#define lsb(i) ((i) & -(i))
using namespace std;
const int c=300002;
int n, q, ert[c], t[c], valasz[c], pos=0, si;
vector<pair<int, int> > sz;
vector<pair<pair<int, int>, int> > s;
void sub(int a) {
    while(a<=n) t[a]--, a+=lsb(a);
}
void add(int a) {
    while(a<=n) t[a]++, a+=lsb(a);
}
int ask(int a) {
    int ans=0;
    while(a>0) ans+=t[a], a-=lsb(a);
    return ans+t[0];
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
        if (ert[i]<=i) {
            int lo=-1, hi=i;
            while (hi-lo>1) {
                int mid=(hi+lo)/2;
                if (ask(mid)+ert[i]>=i) lo=mid;
                else hi=mid;
            }
            if (hi) {
                t[0]++;
                sub(hi);
            }
            sz.push_back({hi, i});
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        s.push_back({{a, b}, i});
    }
    si=sz.size();
    sort(s.rbegin(), s.rend()), sort(sz.rbegin(), sz.rend());
    for (int i=1; i<=n; i++) t[i]=0;
    for (int i=0; i<q; i++) {
        int fi=s[i].first.first, se=s[i].first.second, id=s[i].second;
        while(pos<si && sz[pos].first>fi) add(sz[pos].second), pos++;
        valasz[id]=ask(n-se)-ask(fi);
    }
    for (int i=1; i<=q; i++) cout << valasz[i] << "\n";
    return 0;
}
/*
5 2
1 10 10 10 4
0 0
1 0
*/