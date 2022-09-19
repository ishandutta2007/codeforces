#include <bits/stdc++.h>

using namespace std;
int w, a, b, ab, ba, n;
int bal, jobb, spec;
vector<int> bj, jb;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        bal=0, jobb=0, spec=0;
        bj.clear(), jb.clear();
        cin >> a >> b >> ab >> ba;
        cin >> s;
        n=s.size();
        int dif=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='A') dif++;
            else dif--;
        }
        if (dif!=a-b) {
            cout << "NO\n";
            continue;
        }
        int len=0;
        for (int i=1; i<=n; i++) {
            if (i==n || s[i]==s[i-1]) {
                if (len) {
                    if (len%2==0) {
                        spec+=len/2;
                    } else {
                        int ert=(len+1)/2;
                        if (s[i-len]=='B') {
                            bal+=ert;
                            bj.push_back(ert);
                        } else {
                            jobb+=ert;
                            jb.push_back(ert);
                        }
                    }
                    len=0;
                }
            } else {
                len++;
            }
        }
        sort(bj.rbegin(), bj.rend());
        sort(jb.rbegin(), jb.rend());
        while (spec && bal<ab) {
            bal++;
            spec--;
        }
        while (spec && jobb<ba) {
            jobb++;
            spec--;
        }
        dif=bal+jobb-ab-ba;
        if (bal<ab) {
            int si=jb.size();
            for (int i=0; i<min(si, dif); i++) {
                bal+=jb[i]-1;
            }
        } else if (jobb<ba) {
            int si=bj.size();
            for (int i=0; i<min(si, dif); i++) {
                jobb+=bj[i]-1;
            }
        }
        cout << (bal>=ab && jobb>=ba ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
1 1 0 1
ABAB
*/