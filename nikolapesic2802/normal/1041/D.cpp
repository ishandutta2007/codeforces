#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h;
    scanf("%i %i",&n,&h);
    int udaljenost[n+1];
    udaljenost[0]=0;
    udaljenost[n]=2147483647;
    pair<int,int> interval[n];
    for(int i=0;i<n;i++)
    {
        int x1,x2;
        scanf("%i %i",&x1,&x2);
        interval[i].first=x1;
        interval[i].second=x2;
        if(i>0)
        {
            udaljenost[i]=udaljenost[i-1]+x1-interval[i-1].second;
            //printf("%i\n",udaljenost[i]);
        }
    }
    int maxx=h;
    for(int i=0;i<n;i++)
    {
        int m_uda=udaljenost[i]+h;
        int a=i,b=n-1;
        int res;
        while(true)
        {
            int midd=(a+b)/2;
            if(udaljenost[midd]<m_uda)
            {
                if(udaljenost[midd+1]<m_uda)
                {
                    a=midd+1;
                }
                else
                {
                    res=midd;
                    break;
                }
            }
            else
            {
                b=midd-1;
            }
        }
        int dist=interval[res].second-interval[i].first;
        //printf("Udaljenost od %i do %i: %i preostalo:%i %i   %i\n",i,res,dist,m_uda,udaljenost[res],m_uda-udaljenost[res]);
        dist+=m_uda-udaljenost[res];
        maxx=max(maxx,dist);
    }
    printf("%i\n",maxx);
    return 0;
}