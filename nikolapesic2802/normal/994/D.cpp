#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    pair<int,int> s1[n],s2[m];
    set<int> broj1[n],broj2[m];
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        s1[i].first=a;
        s1[i].second=b;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        s2[i].first=a;
        s2[i].second=b;
    }
    int koliko=0;
    int moguci[10]={};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a=s1[i].first;
            int b=s1[i].second;
            int c=s2[j].first;
            int d=s2[j].second;
            //printf("%i %i - %i %i\n",a,b,c,d);
            if(a==d&&b!=c)
            {
                //printf("1 %i\n",a);
                moguci[a]++;
                broj1[i].insert(a);
                broj2[j].insert(a);
            }
            if(a!=d&&b==c)
            {
                //printf("2 %i\n",b);
                moguci[b]++;
                broj1[i].insert(b);
                broj2[j].insert(b);
            }
            if(a==c&&b!=d)
            {
                //printf("3 %i\n",a);
                moguci[a]++;
                broj1[i].insert(a);
                broj2[j].insert(a);
            }
            if(a!=c&&b==d)
            {
                //printf("4 %i\n",b);
                moguci[b]++;
                broj1[i].insert(b);
                broj2[j].insert(b);
            }
        }
    }
    int koji;
    for(int i=1;i<10;i++)
    {
        if(moguci[i]>0)
        {
            koliko++;
            koji=i;
        }
    }
    if(koliko==1)
    {
        printf("%i\n",koji);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(broj1[i].size()>1)
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(broj2[i].size()>1)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}