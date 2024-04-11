#include <bits/stdc++.h>
using namespace std;

int n, t;

char a[1000007], b[1000007], c[1000007];

int roz, sam;

int licz;

vector <int> wek;

int main()
{
    scanf("%d%d", &n, &t);
    scanf("%s%s", a+1, b+1);
    for (int i=1; i<=n; i++)
    {
        c[i]=a[i];
        if (a[i]!=b[i])
        {
            roz++;
            wek.push_back(i);
        }
        else
        sam++;
    }
    if (((roz+1)/2)>t)
    {
        printf("-1\n");
        return 0;
    }
    licz=t;
    for (int i=0; i<wek.size(); i++)
    {
        if ((wek.size()-i)>licz && i<wek.size()-1)
        {
            c[wek[i]]=a[wek[i]];
            i++;
            c[wek[i]]=b[wek[i]];
            licz--;
        }
        else
        {
            if (a[wek[i]]!='a' && b[wek[i]]!='a')
            c[wek[i]]='a';
            if (a[wek[i]]!='b' && b[wek[i]]!='b')
            c[wek[i]]='b';
            if (a[wek[i]]!='c' && b[wek[i]]!='c')
            c[wek[i]]='c';
            licz--;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (a[i]==b[i] && licz)
        {
            if (a[i]=='a')
            c[i]='b';
            else
            c[i]='a';
            licz--;
        }
    }
    for (int i=1; i<=n; i++)
    {
        printf("%c", c[i]);
    }
    return 0;
}