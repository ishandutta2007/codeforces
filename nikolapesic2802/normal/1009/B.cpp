#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=100005;
    char niz[N];
    scanf("%s",niz);
    string s=niz;
    int broj=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            broj++;
        }
    }
    bool da=true;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            printf("0");
        }
        if(s[i]=='2')
        {
            if(da)
            {
                da=false;
                for(int i=0; i<broj; i++)
                {
                    printf("1");
                }
            }
            printf("2");
        }
    }
    if(da)
    {
        for(int i=0; i<broj; i++)
                {
                    printf("1");
                }
    }
    return 0;
}