#include <bits/stdc++.h>
using namespace std;

int n, k;

long long pun[1000007];
long long kosz[1000007];

int poza[1000007];
int tu[1000007];

vector <int> wek[1000007];
int sum[1000007];

int juz;

long long inf=(long long)1000000000*1000000000;

long long wyn=inf;
long long aktu;

vector <int> dos;

int mniej(int a, int b)
{
    return kosz[a]>kosz[b];
}

int main()
{
    scanf("%d%d", &n, &k);
    if (k==n+1)
    {
        printf("0\n");
        return 0;
    }
    k=n-k+1;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &pun[i]);
        scanf("%lld", &kosz[i]);
        pun[i]=min(pun[i], (long long)n+1);
        wek[pun[i]].push_back(i);
    }
    for (int i=0; i<=n+1; i++)
    {
        sum[i]+=wek[i].size();
        sum[i+1]+=sum[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (i==1)
        tu[i]=k;
        else
        tu[i]=k-sum[i-2];
        tu[i]=max(tu[i], 0);
    }
    for (int i=1; i<=n && juz<=5; i++)
    {
        if (tu[i]>wek[i].size()+wek[i-1].size() || tu[i]>i)
        continue;

        juz++;
        aktu=0;
        dos.clear();

        for (int j=0; j<wek[i].size(); j++)
        dos.push_back(wek[i][j]);
        for (int j=0; j<wek[i-1].size(); j++)
        dos.push_back(wek[i-1][j]);

        sort(dos.begin(), dos.end(), mniej);

        for (int j=1; j<=tu[i]; j++)
        {
            aktu+=kosz[dos.back()];
            dos.pop_back();
        }

        for (int l=0; l<=n+1; l++)
        {
            if (l==i || l+1==i)
            continue;
            for (int j=0; j<wek[l].size(); j++)
            dos.push_back(wek[l][j]);
        }

        sort(dos.begin(), dos.end(), mniej);

        for (int j=1; j<=i-tu[i]; j++)
        {
            aktu+=kosz[dos.back()];
            dos.pop_back();
        }

        wyn=min(wyn, aktu);
    }
    if (wyn==inf)
    printf("-1\n");
    else
    printf("%lld\n", wyn);
    return 0;
}