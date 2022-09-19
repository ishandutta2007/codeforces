#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], f[c], cnt;
long long ans;
vector<int> sz;
map<int, int> m;

int lsb(int a) {
    return (a & -a);
}
void add(int a) {
    while (a<=cnt) {
        f[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int sum=0;
    while (a) {
        sum+=f[a];
        a-=lsb(a);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sz.push_back(t[i]);
        }
        sort(sz.begin(), sz.end());
        sz.erase(unique(sz.begin(), sz.end()), sz.end());
        for (auto x:sz) {
            m[x]=++cnt;
        }
        for (int i=1; i<=n; i++) {
            int s=m[t[i]];
            int bal=ask(s-1), jobb=i-1-ask(s);
            ans+=min(bal, jobb);
            add(s);
        }
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            t[i]=0, f[i]=0;
        }
        cnt=0, ans=0;
        sz.clear(), m.clear();
    }
    return 0;
}