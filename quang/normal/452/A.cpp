#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define make_pair mp
#define X first
#define Y second
#define filein "inp.txt"
#define fileout "out.txt"

#define oo
#define maxn

using namespace std;

vector <string> nhom;

int n;
string sau;

void chuanbi()
{
    nhom.push_back("jolteon");
    nhom.push_back("flareon");
    nhom.push_back("umbreon");
    nhom.push_back("leafeon");
    nhom.push_back("glaceon");
    nhom.push_back("sylveon");
}

bool kt(string b)
{
    FOR(i, 0, 6)
    if(sau[i] != '.' && sau[i] != b[i]) return 0;
    return 1;
}

int main()
{
   // freopen(filein, "r", stdin);
   // freopen(fileout, "w", stdout);
    chuanbi();
    Ri(n);
    cin >> sau;
    if(n == 8) cout << "vaporeon";
    else
        if(n == 6) cout << "espeon";
        else
        {
            FOR(i, 0, 5)
            if(kt(nhom[i]))
            {
                cout << nhom[i];
                return 0;
            }
        }

    return 0;
}