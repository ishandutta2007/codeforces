#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p;
    scanf("%i %i",&n,&p);
    char niz[n];
    char resenje[n];
    scanf("%s",niz);
    bool test=false;
    for(int i=0;i<n-p;i++)
    {
        char a=niz[i];
        char b=niz[i+p];
        if(a!='.'&&a==b)
        {

        }
        else
        {
            if(a=='.'&&b=='.')
            {
                niz[i]='0';
                niz[i+p]='1';
            }
            else
            {
                if(a=='.')
                {
                    if(b=='0')
                    {
                        niz[i]='1';
                    }
                    else
                    {
                        niz[i]='0';
                    }
                }
                if(b=='.')
                {
                    if(a=='0')
                    {
                        niz[i+p]='1';
                    }
                    else
                    {
                        niz[i+p]='0';
                    }
                }
            }
            test=true;
        }
    }
    if(test)
    {
        for(int i=0;i<n;i++)
        {
            if(niz[i]=='.')
            {
                printf("%c",'0');
            }
            else
            {
                printf("%c",niz[i]);
            }
        }
        printf("\n");
        return 0;
    }
    printf("No\n");
    return 0;
}