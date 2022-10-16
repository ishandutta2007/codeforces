#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%i %i %i %i",&a,&b,&c,&d);
    int m=50;
    int res[50][50];
    vector<pair<int,int> > xx;
    xx.push_back(make_pair(a,0));
    xx.push_back(make_pair(b,1));
    xx.push_back(make_pair(c,2));
    xx.push_back(make_pair(d,3));
    sort(xx.begin(),xx.end());
    int dokle=0;
    pair<int,int> prosli;
    while(xx[2].first>0)
    {
        int tr=xx[3].first-1;
        xx[3].first=0;
        xx[2].first--;
        prosli=xx[3];
        int kol=tr/25;
        while(kol)
        {
            for(int i=0; i<50; i++)
            {
                if(i%2==0)
                {
                    res[dokle][i]=xx[3].second;
                }
                else
                {
                    res[dokle][i]=xx[2].second;
                }
            }
            dokle++;
            for(int i=0; i<50; i++)
            {
                res[dokle][i]=xx[2].second;
            }
            dokle++;
            kol--;
        }
        kol=tr%25;
        if(kol>0)
        {
            //printf("Usao");
            for(int i=0; i<kol*2; i++)
            {
                if(dokle%2==0)
                {
                    if(i%2==0)
                    {
                        res[dokle][i]=xx[3].second;
                    }
                    else
                    {
                        res[dokle][i]=xx[2].second;
                    }
                }
                else
                {
                    if(i%2==1)
                    {
                        res[dokle][i]=xx[3].second;
                    }
                    else
                    {
                        res[dokle][i]=xx[2].second;
                    }
                }
            }
            for(int i=kol*2; i<50; i++)
            {
                res[dokle][i]=xx[2].second;
            }
            dokle++;
        }
        for(int i=0; i<50; i++)
        {
            res[dokle][i]=xx[2].second;
        }
        dokle++;
        for(int i=0; i<50; i++)
        {
            res[dokle][i]=xx[3].second;
        }
        dokle++;
        sort(xx.begin(),xx.end());
    }
    if(xx[3].first>0)
    {
        xx[2]=prosli;
        int tr=xx[3].first-1;
        xx[3].first=0;
        xx[2].first--;
        int kol=tr/25;
        while(kol)
        {
            for(int i=0; i<50; i++)
            {
                if(i%2==0)
                {
                    res[dokle][i]=xx[3].second;
                }
                else
                {
                    res[dokle][i]=xx[2].second;
                }
            }
            dokle++;
            for(int i=0; i<50; i++)
            {
                res[dokle][i]=xx[2].second;
            }
            dokle++;
            kol--;
        }
        kol=tr%25;
        if(kol>0)
        {
            //printf("Usao");
            for(int i=0; i<kol*2; i++)
            {
                if(dokle%2==0)
                {
                    if(i%2==0)
                    {
                        res[dokle][i]=xx[3].second;
                    }
                    else
                    {
                        res[dokle][i]=xx[2].second;
                    }
                }
                else
                {
                    if(i%2==1)
                    {
                        res[dokle][i]=xx[3].second;
                    }
                    else
                    {
                        res[dokle][i]=xx[2].second;
                    }
                }
            }
            for(int i=kol*2; i<50; i++)
            {
                res[dokle][i]=xx[2].second;
            }
            dokle++;
        }
        for(int i=0; i<50; i++)
        {
            res[dokle][i]=xx[2].second;
        }
        dokle++;
        for(int i=0; i<50; i++)
        {
            res[dokle][i]=xx[3].second;
        }
        dokle++;
    }
    printf("%i %i\n",dokle,50);
    for(int i=0; i<dokle; i++)
    {
        for(int j=0; j<50; j++)
        {
            printf("%c",'A'+res[i][j]);
        }
        printf("\n");
    }
    return 0;
}