#include <bits/stdc++.h>
using namespace std;

int n, m;
int k;

char wcz[2107];

vector <int> wek;
vector <int> wzo1;
vector <int> wzo2;

vector < pair <int,int> > wyn;

int kmp1[10007];
int kmp2[10007];

int szu[10007];

int l;

int mak;

int main()
{
    scanf("%s", wcz);
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        break;
        wzo1.push_back(wcz[i]);
    }
    scanf("%s", wcz);
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        break;
        wek.push_back(wcz[i]);
    }
    wzo2=wzo1;
    reverse(wzo2.begin(), wzo2.end());
    while(!wek.empty())
    {
        n=wek.size();
        m=wzo1.size();
        k=n+m+1;
        for (int i=0; i<n; i++)
        {
            szu[i+1]=wek[i];
        }
        szu[n+1]=-1;
        for (int i=0; i<m; i++)
        {
            szu[n+2+i]=wzo1[i];
        }
        for (int i=0; i<=k; i++)
        {
            kmp1[i]=0;
        }
        for (int i=2; i<=k; i++)
        {
            l=kmp1[i-1];
            while(l && szu[i]!=szu[l+1])
            l=kmp1[l];
            if (szu[i]==szu[l+1])
            l++;
            kmp1[i]=l;
        }
        n=wek.size();
        m=wzo2.size();
        k=n+m+1;
        for (int i=0; i<n; i++)
        {
            szu[i+1]=wek[i];
        }
        szu[n+1]=-1;
        for (int i=0; i<m; i++)
        {
            szu[n+2+i]=wzo2[i];
        }
        for (int i=0; i<=k; i++)
        {
            kmp2[i]=0;
        }
        for (int i=2; i<=k; i++)
        {
            l=kmp2[i-1];
            while(l && szu[i]!=szu[l+1])
            l=kmp2[l];
            if (szu[i]==szu[l+1])
            l++;
            kmp2[i]=l;
        }
        mak=0;
        for (int i=n+2; i<=k; i++)
        {
            mak=max(mak, kmp1[i]);
            mak=max(mak, kmp2[i]);
        }
        if (!mak)
        {
            printf("-1\n");
            return 0;
        }
        for (int i=n+2; i<=k; i++)
        {
            if (kmp1[i]==mak)
            {
                wyn.push_back(make_pair(i-(n+1)-kmp1[i]+1, i-(n+1)));
                break;
            }
            if (kmp2[i]==mak)
            {
                wyn.push_back(make_pair(m+1-(i-(n+1)-kmp2[i]+1), m+1-(i-(n+1))));
                break;
            }
        }
        for (int i=0; i+mak<wek.size(); i++)
        wek[i]=wek[i+mak];
        while(mak--)
        wek.pop_back();
    }
    printf("%d\n", (int) wyn.size());
    for (int i=0; i<wyn.size(); i++)
    printf("%d %d\n", wyn[i].first, wyn[i].second);
    return 0;
}