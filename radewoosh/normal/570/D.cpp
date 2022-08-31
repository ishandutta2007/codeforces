#include <bits/stdc++.h>
using namespace std;

int n, m;

char lit[1000007];

int oj[1000007];
vector <int> graf[1000007];

int gle[1000007];

int li;

int pre[1000007];
int post[1000007];

vector <int> rzad[1000007];

int liczaj;
int kol[1000007];

int roz[500007][26];

int l, p;

int w, ile;

int bsa, bsb, bss;

int wzap[26];

int czyd;
int czyn;

void dfs(int v)
{
    li++;
    pre[v]=li;

    liczaj++;
    kol[v]=liczaj;
    if (rzad[gle[v]].size()>0)
    {
        for (int j=0; j<26; j++)
        {
            roz[liczaj][j]=roz[kol[rzad[gle[v]].back()]][j];
        }
    }
    rzad[gle[v]].push_back(v);

    roz[liczaj][lit[v]-'a']++;

    for (int i=0; i<graf[v].size(); i++)
    dfs(graf[v][i]);

    li++;
    post[v]=li;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=2; i<=n; i++)
    {
        scanf("%d", &oj[i]);
        graf[oj[i]].push_back(i);
    }
    scanf("%s", lit);
    for (int i=n; i; i--)
    {
        lit[i]=lit[i-1];
    }
    gle[1]=1;
    for (int i=1; i<=n; i++)
    {
        gle[i]=gle[oj[i]]+1;
    }
    dfs(1);
    while(m--)
    {
        scanf("%d%d", &w, &ile);
        if (rzad[ile].empty() || pre[rzad[ile][0]]>post[w] || post[rzad[ile].back()]<pre[w])
        {
            printf("Yes\n");
            continue;
        }
        bsa=0;
        bsb=rzad[ile].size()-1;
        //printf("\n%d   %d %d\n", ile, bsa, bsb);
        while(bsa<bsb)
        {
            bss=(bsa+bsb)>>1;
            if (pre[rzad[ile][bss]]>=pre[w])
            {
                bsb=bss;
            }
            else
            {
                bsa=bss+1;
            }
        }
        bsa--;
        //printf("%d\n", bsa);
        for (int i=0; i<26; i++)
        wzap[i]=0;
        if (bsa>=0)
        {
            for (int i=0; i<26; i++)
            {
                wzap[i]-=roz[kol[rzad[ile][bsa]]][i];
            }
        }
        //for (int i=0; i<26; i++)
        //{
            //wzap[i]+=roz[kol[rzad[ile][bsa]]][i];
            //printf("%d %d\n", i, wzap[i]);
        //}
        bsa=0;
        bsb=rzad[ile].size()-1;
        while(bsa<bsb)
        {
            bss=(bsa+bsb+2)>>1;
            if (pre[rzad[ile][bss]]>post[w])
            {
                bsb=bss-1;
            }
            else
            {
                bsa=bss;
            }
        }
        //printf("%d\n", bsa);
        if (bsa>=0)
        {
            for (int i=0; i<26; i++)
            {
                wzap[i]+=roz[kol[rzad[ile][bsa]]][i];
            }
        }
        czyn=0;
        for (int i=0; i<26; i++)
        {
            if (wzap[i]&1)
            czyn++;
        }
        if (czyn<=1)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}