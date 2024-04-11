#include <bits/stdc++.h>

using namespace std;
const int c=400002;
map<pair<long long, long long>, int> m;
int n, cnt, eler[c], fel[c], cnt2;
vector<pair<int, int> > sz[c], sol;
bool v[c];

bool dfs(int a) {
    v[a]=true;
    eler[a]=++cnt2;
    vector<int> s;
    for (auto el:sz[a]) {
        int x=el.first, id=el.second;
        if (!v[x]) {
            fel[x]=id;
            if (!dfs(x)) {
                s.push_back(id);
            }
        } else {
            if(eler[x]>eler[a]) {
                s.push_back(id);
            }
        }
    }
    int si=s.size();
    bool ans=0;
    if (si%2 && fel[a]) {
        ans=1;
        si++;
        s.push_back(fel[a]);
    }
    for (int i=1; i<si; i+=2) {
        sol.push_back({s[i-1], s[i]});
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b, c, d, bal1, bal2, bgcd, jobb1, jobb2, jgcd;
        cin >> a >> b >> c >> d;
        bal1=(a+b)*d, bal2=b*c, bgcd=__gcd(bal1, bal2);
        jobb1=a*d, jobb2=b*(c+d), jgcd=__gcd(jobb1, jobb2);
        bal1/=bgcd, bal2/=bgcd, jobb1/=jgcd, jobb2/=jgcd;
        pair<long long, long long> bp={bal1, bal2}, jp={jobb1, jobb2};
        if (!m[bp]) {
            m[bp]=++cnt;
        }
        if (!m[jp]) {
            m[jp]=++cnt;
        }
        //cout << "el " << m[bp] << " " << m[jp] << "\n";
        sz[m[bp]].push_back({m[jp], i});
        sz[m[jp]].push_back({m[bp], i});
    }
    for (int i=1; i<=cnt; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    cout << sol.size() << "\n";
    for (auto x:sol) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}