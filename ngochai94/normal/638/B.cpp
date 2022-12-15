#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000003
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, has[26], cnt[26], after[26];
string s;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    reset(after, -1);
    while (n--)
    {
        cin >> s;
        //BUG(s);
        for (char c: s) has[c - 'a'] = 1;
        //BUG(s.size() - 2);
        REP (i, s.size() - 1)
        //FOR (i, 0, s.size() - 2)
        {
            //BUG(i);
            cnt[s[i + 1] - 'a'] = 1;
            after[s[i] - 'a'] = s[i + 1] - 'a';
        }
    }
    //BUG(has[0]);
    s = "";
    while (1)
    {
        bool flag = false;
        REP (i, 26) if (has[i] && !cnt[i])
        {
            //BUG(i);
            flag = true;
            int tmp = i;
            while (tmp != -1)
            {
                has[tmp] = 0;
                s += ('a' + tmp);
                tmp = after[tmp];
            }
        }
        if (!flag) break;
    }
    cout << s;
}