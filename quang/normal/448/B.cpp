#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>
#define maxn
#define oo
#define X first
#define Y second
#define FOR(i, a, b) for(int i = (a); i <= (b);i++)
#define FORN(i, a, b) for(int i = (a); i >= (b);i--)
#define filein "B.inp"
#define fileout "B.out"

using namespace std;

string s, t;
int sl[2][30];

void nhap()
{
    cin >> s >> t;
}

bool KT()
{
    FOR(i, 0, 29) if(sl[0][i] != sl[1][i]) return 0;
    return 1;
}

bool KT2()
{
    FOR(i, 0, 29) if(sl[1][i] > sl[0][i]) return 0;
    return 1;
}

bool KT3()
{
    int cur = 0;
    FOR(i, 0, (int) s.size() - 1)
    {
        if(s[i] == t[cur])
        {
            cur++;
            if(cur == (int)t.size()) return 1;
        }
    }
    return (cur == (int)t.size());
}

void xuli()
{
    if(KT3())
    {
        cout << "automaton";
        return;
    }
    memset(sl, 0, sizeof(sl));
    FOR(i, 0, (int)s.size() - 1) sl[0][s[i] - 'a']++;
    FOR(i, 0, (int)t.size() - 1) sl[1][t[i] - 'a']++;
    if(KT())
    {
        cout << "array";
        return;
    }
    if(KT2()) cout << "both";
    else cout << "need tree";
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    xuli();
    return 0;
}