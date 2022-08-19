#include <bits/stdc++.h>
using namespace std;

int n;
int h, w;

int m;

char wcz[500007];

int k=1000100;
long long poz[2100007];
long long pio[2100007];

long long mod=1000000007;
long long inf;

int g;

vector <long long> jed, dwa;

int it;

long long wyn;

int main()
{
    inf=1000000000;
    inf*=inf;
    scanf("%d", &n);
    scanf("%d%d", &h, &w);
    m=max(m, n);
    m=max(m, h);
    m=max(m, w);
    scanf("%s", wcz+1);
    for (int i=0; i<=2*k; i++)
    {
        poz[i]=inf;
        pio[i]=inf;
    }
    poz[k]=0;
    pio[k]=0;
    g=0;
    for (int i=1; i<=n; i++)
    {
        if (wcz[i]=='L')
        g--;
        if (wcz[i]=='R')
        g++;
        poz[g+k]=min(poz[g+k], (long long)i);
    }
    for (int i=-m; i<=m; i++)
    {
        poz[i+g+k]=min(poz[i+g+k], poz[i+k]+n);
    }
    for (int i=m; i>=-m; i--)
    {
        poz[i+g+k]=min(poz[i+g+k], poz[i+k]+n);
    }
    g=0;
    for (int i=1; i<=n; i++)
    {
        if (wcz[i]=='D')
        g--;
        if (wcz[i]=='U')
        g++;
        pio[g+k]=min(pio[g+k], (long long)i);
    }
    for (int i=-m; i<=m; i++)
    {
        pio[i+g+k]=min(pio[i+g+k], pio[i+k]+n);
    }
    for (int i=m; i>=-m; i--)
    {
        pio[i+g+k]=min(pio[i+g+k], pio[i+k]+n);
    }

    for (int i=1; i<=h; i++)
    {
        jed.push_back(min(pio[k-i], pio[k+(h-i+1)]));
    }
    for (int i=1; i<=w; i++)
    {
        dwa.push_back(min(poz[k-i], poz[k+(w-i+1)]));
    }

    sort(jed.begin(), jed.end());
    sort(dwa.begin(), dwa.end());
    if (jed.back()>=inf && dwa.back()>=inf)
    {
        printf("-1\n");
        return 0;
    }

    it=dwa.size();
    for (int i=jed.size()-1; i>=0; i--)
    {
        while(it && dwa[it-1]>=jed[i])
        {
            it--;
        }
        wyn+=jed[i]*(dwa.size()-it);
        wyn%=mod;
    }
    it=jed.size();
    for (int i=dwa.size()-1; i>=0; i--)
    {
        while(it && jed[it-1]>dwa[i])
        {
            it--;
        }
        wyn+=dwa[i]*(jed.size()-it);
        wyn%=mod;
    }

    printf("%lld\n", wyn);

    return 0;
}