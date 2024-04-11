#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<vector<int> > graf(n);
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        graf[a].push_back(i);
    }
    int da[n];
    for(int i=0;i<n;i++)
    {
        if(graf[i].size()==0)
        {
            da[i]=1;
        }
        else
        {
            da[i]=0;
        }
        //printf("%i %i\n",i+1,da[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(da[i]==0)
        {
            int broj=0;
            for(int j=0;j<graf[i].size();j++)
            {
                int sl=graf[i][j];
                if(da[sl]==1)
                {
                    broj++;
                }
            }
            if(broj<3)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
    return 0;
}