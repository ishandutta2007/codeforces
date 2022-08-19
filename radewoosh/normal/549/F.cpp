#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long k;

int n1;

int tab[300007];
int pre[300007];

pair <int,int> drzewo[2100000];


vector < int > zapp[300007];
vector < int > zapm[300007];

long long licz;

long long wyn;

int ile[1000007];

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

void pisz(int v, int war)
{
    pair <int,int> dow=make_pair(war, v);
    v+=n1-1;
    while(v)
    {
        drzewo[v]=max(drzewo[v], dow);
        v>>=1;
    }
}

pair <int,int> czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        return drzewo[v];
    }
    if (a>grab || b<graa)
    {
        return make_pair(0, 0);
    }
    return max( czyt((v<<1), a, (a+b)>>1, graa, grab) , czyt((v<<1)+1, (a+b+2)>>1, b, graa, grab) );
}

void rek(int l, int p)
{
    if (l>=p)
    {
        return;
    }
    int x=czyt(1, 1, n1, l, p).second;
    rek(l, x-1);
    rek(x+1, p);
    if (x-l<=p-x)
    {
        for (int i=x; i>=l; i--)
        {
            licz=((k-(pre[x-1]-pre[i-1])+pre[x])%k+k)%k;
            zapp[p].push_back(licz);
            if (i!=x)
            zapm[x-1].push_back(licz);
            else
            zapm[x].push_back(licz);
            //printf("%d %d   jed %d %d     %lld\n", l, p, p, x, licz);
        }
    }
    else
    {
        for (int i=x; i<=p; i++)
        {
            licz=((k+(pre[i]-pre[x])+pre[x-1])%k+k)%k;
            if (x!=i)
            zapp[x-1].push_back(licz);
            else if (x!=1)
            zapp[x-2].push_back(licz);
            if (l!=1)
            zapm[l-2].push_back(licz);
            //printf("%d %d   jed %d %d     %lld\n", l, p, p, x, licz);
        }
    }
    /*if (x<p)
    {
        licz=(k+k+k+pre[x])%k;
        zap[p].push_back(make_pair(licz, 1));
        zap[x+1].push_back(make_pair(licz, -1));
        printf("%d %d   dwa %d %d     %lld\n", l, p, p, x+1, licz);
    }
    if (x>l)
    {
        licz=(k+k+k+pre[x-1])%k;
        zap[x-2].push_back(make_pair(licz, 1));
        zap[l-1].push_back(make_pair(licz, -1));
        printf("%d %d   dwa %d %d     %lld\n", l, p, x-2, l-1, licz);
    }*/
}

int main()
{
    scanf("%d%lld", &n, &k);
    n1=potenga(n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        pisz(i, tab[i]);
        pre[i]=tab[i]+pre[i-1];
        pre[i]%=k;
    }
    rek(1, n);
    for (int i=0; i<=n; i++)
    {
        ile[pre[i]]++;
        for (int j=0; j<zapp[i].size(); j++)
        {
            wyn+=ile[zapp[i][j]];
        }
        for (int j=0; j<zapm[i].size(); j++)
        {
            wyn-=ile[zapm[i][j]];
        }
    }
    printf("%lld", wyn);
    return 0;
}