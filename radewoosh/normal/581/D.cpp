#include <bits/stdc++.h>
using namespace std;

int x[5], y[5];

bitset <10> bity;

int per[5];

int main()
{
    per[0]=0;
    per[1]=1;
    per[2]=2;
    scanf("%d%d", &x[0], &y[0]);
    scanf("%d%d", &x[1], &y[1]);
    scanf("%d%d", &x[2], &y[2]);
    for (int h=0; h<8; h++)
    {
        bity=h;
        for (int i=0; i<3; i++)
        {
            if (bity[i])
            {
                swap(x[i], y[i]);
            }
        }

        if (x[0]==x[1] && x[0]==x[2] && y[0]+y[1]+y[2]==x[0])
        {
            printf("%d\n", x[0]);
            for (int i=1; i<=x[0]; i++)
            {
                for (int j=1; j<=x[0]; j++)
                {
                    if (i<=y[0])
                    {
                        printf("A");
                        continue;
                    }
                    if (i<=y[0]+y[1])
                    {
                        printf("B");
                        continue;
                    }
                    if (i<=y[0]+y[1]+y[2])
                    {
                        printf("C");
                        continue;
                    }
                }
                printf("\n");
            }
            return 0;
        }

        for (int i=1; i<=6; i++)
        {
            next_permutation(per, per+3);
            if (x[per[0]]==x[per[1]]+x[per[2]] && y[per[1]]==y[per[2]] && x[per[0]]==y[per[0]]+y[per[1]])
            {
                printf("%d\n", x[per[0]]);
                for (int i=1; i<=x[per[0]]; i++)
                {
                    for (int j=1; j<=x[per[0]]; j++)
                    {
                        if (i<=y[per[0]])
                        {
                            if (per[0]==0)
                            printf("A");
                            if (per[0]==1)
                            printf("B");
                            if (per[0]==2)
                            printf("C");
                            continue;
                        }
                        if (j<=x[per[1]])
                        {
                            if (per[1]==0)
                            printf("A");
                            if (per[1]==1)
                            printf("B");
                            if (per[1]==2)
                            printf("C");
                            continue;
                        }
                        if (j>x[per[1]])
                        {
                            if (per[2]==0)
                            printf("A");
                            if (per[2]==1)
                            printf("B");
                            if (per[2]==2)
                            printf("C");
                            continue;
                        }
                    }
                    printf("\n");
                }
                return 0;
            }
        }

        for (int i=0; i<3; i++)
        {
            if (bity[i])
            {
                swap(x[i], y[i]);
            }
        }
    }
    printf("-1\n");
    return 0;
}