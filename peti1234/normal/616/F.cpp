#include <bits/stdc++.h>

using namespace std;

const int c=1000005;
int n, len[c], link[c], last, cnt;
map<char, int> f[c];
long long val[c];
void add(char k) {
    if (f[last][k] && len[f[last][k]]==len[last]+1) {
        last=f[last][k];
        return;
    }
    int p=last;
    last=++cnt;
    len[last]=len[p]+1;
    while (!f[p][k]) {
        f[p][k]=cnt;
        p=link[p];
    }
    int ch=f[p][k];
    if (ch==last) {
        return;
    }
    if (len[ch]==len[p]+1) {
        link[last]=ch;
        return;
    }

    int clone=++cnt;
    len[clone]=len[p]+1;
    f[clone]=f[ch], link[clone]=link[ch];
    link[last]=clone, link[ch]=clone;
    while (f[p][k]==ch) {
        f[p][k]=clone;
        p=link[p];
    }
}
int main()
{
    cin >> n;
    string s[n+1];
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=n; i++) {
        last=0;
        int x;
        cin >> x;
        for (auto c:s[i]) {
            add(c);
            val[last]+=x;
        }
    }

    vector<pair<int, int> > st;
    for (int i=1; i<=cnt; i++) {
        st.push_back({-len[i], i});
    }
    sort(st.begin(), st.end());
    long long ans=0;
    for (auto x:st) {
        int id=x.second;
        ans=max(ans, len[id]*val[id]);
        val[link[id]]+=val[id];
    }
    cout << ans << "\n";
    return 0;
}