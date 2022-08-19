#include <bits/stdc++.h>
using namespace std;

int n;

int tab[50];

int nwd;

int suma;

int pot;

vector <char> wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        suma+=tab[i];
        nwd=__gcd(nwd, tab[i]);
    }
    if (n==1)
    {
        printf("%d\n", tab[1]);
        for (int i=1; i<=tab[1]; i++)
        {
            printf("a");
        }
        printf("\n");
        return 0;
    }
    if (suma&1)
    {
        int licz=0;
        int gdz=0;
        for (int i=1; i<=n; i++)
        {
            if (tab[i]&1)
            {
                licz++;
                gdz=i;
            }
        }
        if (licz==1)
        {
            pot=nwd;

            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=tab[i]/(pot*2); j++)
                {
                    wyn.push_back('a'-1+i);
                }
            }

            for (int i=wyn.size()-1; i>=0; i--)
            {
                wyn.push_back(wyn[i]);
            }

            wyn.push_back('a'-1+gdz);


            int si=wyn.size()-1;
            while(wyn.size()<suma)
            {
                for (int i=0; i<=si; i++)
                {
                    wyn.push_back(wyn[i]);
                }
            }
            printf("%d\n", pot);
            for (int i=0; i<wyn.size(); i++)
            {
                printf("%c", wyn[i]);
            }
            printf("\n");
        }
        else
        {
            printf("0\n");
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=tab[i]; j++)
                {
                    printf("%c", 'a'-1+i);
                }
            }
            printf("\n");
        }
        return 0;
    }

    if (nwd&1)
    {
        printf("0\n");
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=tab[i]; j++)
            {
                printf("%c", 'a'-1+i);
            }
        }
        printf("\n");
        return 0;
    }

    pot=nwd;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=tab[i]/pot; j++)
        {
            wyn.push_back('a'-1+i);
        }
    }

    for (int i=wyn.size()-1; i>=0; i--)
    {
        wyn.push_back(wyn[i]);
    }


    int si=wyn.size()-1;
    while(wyn.size()<suma)
    {
        for (int i=si; i>=0; i--)
        {
            wyn.push_back(wyn[i]);
        }
    }
    printf("%d\n", pot);
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%c", wyn[i]);
    }
    printf("\n");
    return 0;
}