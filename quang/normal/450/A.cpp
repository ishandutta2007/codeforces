#include <bits/stdc++.h>

#define oo
#define maxn 110
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "A.inp"
#define fileout "A.out"

using namespace std;

int n, m;
int a[maxn];
vector < pair<int, int> > b;

void nhap()
{
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
}

void chuanbi()
{
    b.clear();
    FOR(i, 1, n) b.push_back(make_pair(a[i], i));
}

void xuli()
{
    int r = n - 1;
    int l = 0;
    while(l < r)
    {
       if(m < b[l].first)
            b.push_back(make_pair(b[l].first - m, b[l].second)), r++;
       l++;
    }
    cout << b[r].second;
}

void inkq()
{

}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    chuanbi();
    xuli();
    inkq();
    return 0;
}