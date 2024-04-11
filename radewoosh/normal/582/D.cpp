#include <bits/stdc++.h>
using namespace std;

long long p, alf;
char wcz[100007];

vector <long long> sta;
vector <long long> zam;
vector <long long> now;

long long ile(long long v)
{
    long long ret=0;
    while(v)
    {
        ret+=v/p;
        v/=p;
    }
    return ret;
}

long long mod=1000000007;

long long x;

int dpn[3507][3507];
int dpo[3507][3507];

int pa;

int m;

long long chcen[2][3507];
long long chceo[2][3507];

long long wyn;

long long chn, cho;

long long trd(long long v)
{
    return ((v*(v-1))/2)%mod;
}

long long trg(long long v)
{
    return ((v*(v+1))/2)%mod;
}

int main()
{
    scanf("%lld%lld", &p, &alf);
    if (alf>3500)
    {
        printf("0\n");
        return 0;
    }
    /*for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=i+1; j++)
        {
            printf("%d.%d ", dpn[i][j], dpo[i][j]);
        }
        printf("\n");
    }*/
    scanf("%s", wcz+1);
    for (int i=1; 1; i++)
    {
        if (!wcz[i])
        break;
        sta.push_back(wcz[i]-'0');
    }
    reverse(sta.begin(), sta.end());
    sta[0]++;
    sta.push_back(0);
    for (int i=0; i+1<sta.size(); i++)
    {
        if (sta[i]>9)
        {
            sta[i+1]++;
            sta[i]-=10;
        }
    }
    while(!sta.back())
    sta.pop_back();
    while(!sta.empty())
    {
        zam.clear();
        for (int i=0; i<sta.size(); i++)
        zam.push_back(0);
        x=0;
        for (int i=sta.size()-1; i>=0; i--)
        {
            x*=10;
            x+=sta[i];
            zam[i]=(x/p);
            x%=p;
        }
        sta=zam;
        while(!sta.empty() && !sta.back())
        sta.pop_back();
        now.push_back(x);
        //printf("%lld\n", x);
    }
    //m=now.size()+3;
    //m=3500;
    m=now.size()+3;
    dpn[0][0]=1;
    //dpn[0][0]=p*(p+1)/2;
    //dpo[0][1]=p*(p-1)/2;
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<=i+1; j++)
        {
            dpn[i][j]=(trg(p)*dpn[i-1][j]+trd(p)*dpo[i-1][j])%mod;
            if (!j)
            continue;
            dpo[i][j]=(trg(p)*dpo[i-1][j-1]+trd(p)*dpn[i-1][j-1])%mod;
        }
    }
    /*for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=i+1; j++)
        {
            printf("%d.%d ", dpn[i][j], dpo[i][j]);
        }
        printf("\n");
    }*/
    chcen[1&(now.size()-1)][alf]=1;
    for (int i=now.size()-1; i>=0; i--)
    {
        pa=i&1;
        //printf("%lld ", now[i]);
        for (int j=0; j<=i+1; j++)
        {
            chcen[pa^1][j]=0;
            chceo[pa^1][j]=0;
            //printf("%lld.%lld ", chcen[pa][j], chceo[pa][j]);
        }
        //printf("\n");
        for (int j=0; j<=i+1; j++)
        {
            chcen[pa^1][j]+=(chcen[pa][j]*(now[i]+1))%mod;
            chcen[pa^1][j]%=mod;
            chceo[pa^1][j]+=(chcen[pa][j]*(now[i]))%mod;
            chceo[pa^1][j]%=mod;
            chcen[pa^1][max(j-1, 0)]+=(chceo[pa][j]*(p-now[i]-1))%mod;
            chcen[pa^1][max(j-1, 0)]%=mod;
            chceo[pa^1][max(j-1, 0)]+=(chceo[pa][j]*(p-now[i]))%mod;
            chceo[pa^1][max(j-1, 0)]%=mod;
        }
        chn=0;
        cho=0;
        for (int j=0; j<=i+1; j++)
        {
            //printf("%d.%d ", chcen[i][j], chceo[i][j]);
            chn+=chcen[pa][j];
            chn%=mod;
            cho+=chceo[pa][j];
            cho%=mod;


            wyn+=trg(now[i])*((dpn[i][j]*chn)%mod);
            wyn+=trd(now[i])*((dpo[i][j]*chn)%mod);
            wyn%=mod;

            if (!j)
            continue;

            wyn+=(trd(p)-trd(p-now[i])+mod)*((dpn[i][j-1]*cho)%mod);
            wyn+=(trg(p)-trg(p-now[i])+mod)*((dpo[i][j-1]*cho)%mod);
            wyn%=mod;
        }
        //printf("%lld\n", wyn);
    }
    wyn%=mod;
    wyn+=mod;
    wyn%=mod;
    printf("%lld\n", wyn);
    return 0;
}