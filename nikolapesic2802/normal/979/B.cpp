#include <bits/stdc++.h>

using namespace std;
int koliko[100];
int n;
void reset()
{
    for(int i=0;i<100;i++)
    {
        koliko[i]=0;
    }
}
int maks()
{
    int m=0;
    for(int i=0;i<100;i++)
    {
        m=max(m,koliko[i]);
    }
    return m;
}
int update(string s)
{
    reset();
    int siz=s.size();
    for(int i=0;i<siz;i++)
    {
        koliko[s[i]-'A']++;
    }
    int d = maks();
    int do_kraja=siz-d;
    if(do_kraja!=0)
    {
        return min(siz,d+n);
    }
    else
    {
        int ostalo=n-do_kraja;
        if(ostalo==1)
            return siz-1;
        return siz;
    }
}
int main()
{
    scanf("%i",&n);
    const int N=100001;
    char c1[N],c2[N],c3[N];
    scanf("%s %s %s",c1,c2,c3);
    string s1=c1,s2=c2,s3=c3;
    int l1=update(s1);
    int l2=update(s2);
    int l3=update(s3);
    //printf("%i %i %i\n",l1,l2,l3);
    int m=max(max(l1,l2),l3);
    if((l1==l2&&l2==m)||(l2==l3&&l2==m)||(l1==l3&&l3==m))
    {
        printf("Draw\n");
    }
    else
    {
        if(m==l1)
        {
            printf("Kuro\n");
        }
        if(m==l2)
        {
            printf("Shiro\n");
        }
        if(m==l3)
        {
            printf("Katie\n");
        }
    }
    return 0;
}