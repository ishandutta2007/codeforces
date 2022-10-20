#include <bits/stdc++.h>

#define oo
#define maxn 100010
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "D.inp"
#define fileout "D.out"

using namespace std;

struct data
{
    int gt, sodiem, dau;
    data(int _gt = 0,int  _sodiem = 0,int  _dau = 0)
    {
        gt = _gt;
        sodiem = _sodiem;
        dau = _dau;
    }
};

int  n, d;
vector <data> a;
string s;
long long  le[5], chan[5];
long long kqle = 0ll, kqchan = 0ll;

void nhap()
{
    cin >> s;
    n = (int)s.size();
    s = "Q" + s;
}

void chuanbi()
{
    memset(le, 0, sizeof(le));
    memset(chan, 0, sizeof(chan));
    d = 0;
    FOR(i, 1, n)
    if(s[i] != s[i - 1])
    {
        d++;
        a.push_back(data(s[i] - 'a' + 1, 1, i));
    }
    else a[d - 1].sodiem++;
}

void Themdiem(int x)
{
    if(x == 1)
    {
        kqle ++;
        return;
    }
    if(x == 2)
    {
        kqle += 2ll;
        kqchan++;
        return;
    }
    if(x % 2)
    {
        int sl = (x + 1) / 2;
        kqle += 1ll * (x + 1) * sl / 2;
        kqchan += 1ll * (x - 1) * sl / 2;
    }
    else
    {
        int sl = x / 2;
        kqle += 1ll * (x + 2) * sl / 2;
        kqchan += 1ll * x * sl / 2;
    }
}

void xuli()
{
    FOR(i, 0, d - 1)
    {
        Themdiem(a[i].sodiem);
        int slle = (a[i].sodiem + 1) / 2, slchan = (a[i].sodiem) / 2;
        if(a[i].dau % 2 == 0) swap(slle, slchan);
        kqle += 1ll * slle * le[a[i].gt] + 1ll * slchan * chan[a[i].gt];
        kqchan += 1ll * slle * chan[a[i].gt] + 1ll * slchan * le[a[i].gt];
        le[a[i].gt] += slle;
        chan[a[i].gt] += slchan;
    }
}

void inkq()
{
    cout << kqchan << " " << kqle;;
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