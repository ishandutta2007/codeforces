#include <bits/stdc++.h>

using namespace std;

long long ans, d=1337, h=6000;
int n, si, len;
string s, r;
map<string, vector<string> > csop;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s;
        r=s;
        sort(r.begin(), r.end());
        csop[r].push_back(s);
    }
    ans=d*n*(n-1)/2;
    for (auto pp:csop) {
        auto p=pp.second;
        si=p.size(), len=p[0].size();
        ans-=(d-2)*si*(si-1)/2;
        sort(p.begin(), p.end());
        if (si<=h) {
            for (int i=0; i<si; i++) {
                for (int j=i+1; j<si; j++) {
                    int bal=0, jobb=len-1;
                    while (p[i][bal]==p[j][bal]) {
                        bal++;
                    }
                    while (p[i][jobb]==p[j][jobb]) {
                        jobb--;
                    }
                    if (is_sorted(p[i].begin()+bal, p[i].begin()+jobb+1) || is_sorted(p[j].begin()+bal, p[j].begin()+jobb+1)) {
                        ans--;
                    }
                }
            }
        } else {
            for (int i=0; i<si; i++) {
                for (int bal=0; bal<len; bal++) {
                    for (int jobb=bal+1; jobb<len; jobb++) {
                        string alap=p[i], valt=alap;
                        sort(valt.begin()+bal, valt.begin()+jobb+1);
                        if (alap[bal]!=valt[bal] && alap[jobb]!=valt[jobb] && binary_search(p.begin(), p.end(), valt)) {
                            ans--;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}