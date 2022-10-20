#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein "inp.txt"
#define fileout "out.txt"
#define oo
#define maxn

using namespace std;

string s1, s2;

bool kt(string ss)
{
    FOR(i, 0, (int)ss.size() - 1) if(ss[i] == '1') return 1;
    return 0;
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    cin >> s1;
    cin >> s2;
    if(s1.size() != s2.size())
    {
        cout << "NO";
        return 0;
    }
    if(kt(s1) ^ kt(s2)) cout << "NO";
        else cout << "YES";
    return 0;
}