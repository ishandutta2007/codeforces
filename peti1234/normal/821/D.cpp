#include <bits/stdc++.h>

using namespace std;
const int c=10005;
int n, m, k, kezd;
int sor[c], oszlop[c], dist[c], pos, mini=c;
vector<pair<int, int> > s[c], o[c];
bool v[c], vs[c], vo[c];
deque<pair<int, int> > q;
int ker(vector<pair<int, int> > &x, int ert) {
    int lo=0, hi=x.size(), mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (x[mid].first<=ert) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    return lo;
}
void kadd(int a, int b) {
    q.push_front({a, b});
}
void vadd(int a, int b) {
    q.push_back({a, b});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        cin >> sor[i] >> oszlop[i];
        s[sor[i]].push_back({oszlop[i], i});
        o[oszlop[i]].push_back({sor[i], i});
        if (sor[i]==1 && oszlop[i]==1) {
            kezd=i;
        }
    }
    for (int i=1; i<=n; i++) {
        sort(s[i].begin(), s[i].end());
    }
    for (int i=1; i<=m; i++) {
        sort(o[i].begin(), o[i].end());
    }
    kadd(kezd, 0);
    while (q.size()>0) {
        int id=q.front().first, tav=q.front().second;
        q.pop_front();
        if (!v[id]) {
            dist[id]=tav;
            v[id]=1;
            int ss=sor[id], oo=oszlop[id];
            if (!vs[ss]) {
                vs[ss]=1;
                for (int i=max(1, ss-2); i<=ss+2; i++) {
                    for (auto uj:s[i]) {
                        vadd(uj.second, tav+1);
                    }
                }
            }
            if (!vo[oo]) {
                vo[oo]=1;
                for (int i=max(1, oo-2); i<=oo+2; i++) {
                    for (auto uj:o[i]) {
                        vadd(uj.second, tav+1);
                    }
                }
            }
            pos=ker(s[ss], oo);
            if (pos>0 && s[ss][pos-1].first==oo-1) {
                kadd(s[ss][pos-1].second, tav);
            }
            if (pos+1<s[ss].size() && s[ss][pos+1].first==oo+1) {
                kadd(s[ss][pos+1].second, tav);
            }
            pos=ker(o[oo], ss);
            if (pos>0 && o[oo][pos-1].first==ss-1) {
                kadd(o[oo][pos-1].second, tav);
            }
            if (pos+1<o[oo].size() && o[oo][pos+1].first==ss+1) {
                kadd(o[oo][pos+1].second, tav);
            }
        }
    }
    for (int i=1; i<=k; i++) {
        if (v[i]) {
            bool a=(sor[i]>=n-1), b=(oszlop[i]>=m-1);
            int ert=dist[i];
            if (a || b) {
                mini=min(mini, ert+1);
            }
            if (sor[i]==n && oszlop[i]==m) {
                mini=ert;
            }
        }
    }
    if (mini==c) {
        mini=-1;
    }
    cout << mini << "\n";
    return 0;
}