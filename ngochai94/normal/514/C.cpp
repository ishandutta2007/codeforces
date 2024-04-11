#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

int n, m, p1[600005], p2[600005], p3[600005];
set<int> s1[600005], s2[600005], s3[600005];
string s;
 
int main(){
    ios::sync_with_stdio(0);
    p1[0] = p2[0] = 1;
    FOR (i, 1, 600000) {
        p1[i] = p1[i - 1] * 1613 + 7;
        p2[i] = p2[i - 1] * 181 + 11;
        p3[i] = p3[i - 1] * 7907 + 13;
    }
    REP (i, 600000) p1[i] += rand();
    cin >> n >> m;
    while (n--) {
        cin >> s;
        int cur = 0;
        REP (i, s.size()) cur += p1[i] * (s[i] - '`');
        s1[s.size()].insert(cur);
        // BUG(cur);
        cur = 0;
        REP (i, s.size()) cur += p2[i] * (s[i] - '`');
        s2[s.size()].insert(cur);
        cur = 0;
        REP (i, s.size()) cur += p3[i] * (s[i] - '`');
        s3[s.size()].insert(cur);
    }
    while (m--) {
        cin >> s;
        int cur1 = 0;
        int cur2 = 0;
        int cur3 = 0;
        bool flag = false;
        REP (i, s.size()) {
            cur1 += p1[i] * (s[i] - '`');
            cur2 += p2[i] * (s[i] - '`');
            cur3 += p3[i] * (s[i] - '`');
        }
        REP (i, s.size()) {
            // BUG(i);
            if (s[i] == 'a') {
                cur1 += p1[i];
                cur2 += p2[i];
                cur3 += p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 += p1[i];
                cur2 += p2[i];
                cur3 += p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 -= 2 * p1[i];
                cur2 -= 2 * p2[i];
                cur3 -= 2 * p3[i];
            }
            if (s[i] == 'b') {
                cur1 += p1[i];
                cur2 += p2[i];
                cur3 += p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 -= 2 * p1[i];
                cur2 -= 2 * p2[i];
                cur3 -= 2 * p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 += p1[i];
                cur2 += p2[i];
                cur3 += p3[i];
            }
            if (s[i] == 'c') {
                cur1 -= p1[i];
                cur2 -= p2[i];
                cur3 -= p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 -= p1[i];
                cur2 -= p2[i];
                cur3 -= p3[i];
                if (s1[s.size()].count(cur1) && s2[s.size()].count(cur2) && s3[s.size()].count(cur3)) {
                    flag = true;
                    break;
                }
                cur1 += 2 * p1[i];
                cur2 += 2 * p2[i];
                cur3 += 2 * p3[i];
            }
            // BUG(i);

        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}