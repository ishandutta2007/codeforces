#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    scanf("%i %i",&n,&d);
    int m;
    scanf("%i",&m);
    pair<int,int> tacke[n+1];
    for(int i=0;i<=d;i++)
    {
        tacke[i].first=d-i;
        tacke[i].second=d+i;
    }
    for(int i=d+1;i<=n-d;i++)
    {
        tacke[i].first=abs(i-d);
        tacke[i].second=abs(i+d);
    }
    for(int i=0;i<d;i++)
    {
        tacke[n-i].first=abs(n-d-i);
        tacke[n-i].second=abs(n-d+i);
    }
    /*for(int i=0;i<=n;i++)
    {
        printf("od %i do %i\n",tacke[i].first,tacke[i].second);
    }*/
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        if(y>=tacke[x].first&&y<=tacke[x].second)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}