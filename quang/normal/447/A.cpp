#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

#define oo
#define maxn 330
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "A.inp"
#define fileout "A.out"

using namespace std;

int p, n;
bool kt[maxn];

void nhap()
{
    cin >> p >> n;
}

void chuanbi()
{
    memset(kt, 0 ,sizeof(kt));
}

void xuli()
{
    FOR(i, 1, n)
    {
        int x;
        cin >> x;
        if(kt[x % p])
        {
            cout << i;
            exit(0);
        }
        kt[x % p] = 1;
    }
    cout << -1;
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