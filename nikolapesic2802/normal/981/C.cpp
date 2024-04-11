#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<vector<int> > graf;
    vector<int> pom;
    int n;
    scanf("%i",&n);
    int indegree[n];
    for(int i=0;i<n;i++)
    {
        indegree[i]=0;
        graf.push_back(pom);
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        indegree[a]++;
        indegree[b]++;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int cnt=0;
    int gde=-1;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]>2)
        {
            cnt++;
            gde=i;
        }
    }
    if(cnt<=1)
    {
        printf("Yes\n");
        vector<int> tr;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                tr.push_back(i);
            }
        }
        if(cnt==1)
        {
            printf("%i\n",tr.size());
            for(int i=0;i<tr.size();i++)
            {
                printf("%i %i\n",gde+1,tr[i]+1);
            }
        }
        else
        {
            printf("1\n%i %i\n",tr[0]+1,tr[1]+1);
        }
    }
    else
    {
        printf("No\n");
    }
    return 0;
}