#include <bits/stdc++.h>

using namespace std;
const int N=200010;
int visited[N],sl[N];
int main()
{
    int n;
    scanf("%i",&n);
    int cost[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&cost[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&sl[i]);
        sl[i]--;
    }
    int res=0;

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            vector<int> cycle;
            int tr=i;
            while(visited[tr]==0)
            {
                cycle.push_back(tr);
                visited[tr]=1;
                tr=sl[tr];
            }
            if(visited[tr]==1)
            {
                vector<int> cene;
                bool da=true;
                for(int j=cycle.size()-1;j>=0;j--)
                {
                    int s=cycle[j];
                    visited[s]=2;
                    if(da)
                    {
                        //printf("Ciklus:%i\n",s);
                        cene.push_back(cost[s]);
                    }
                    if(s==tr)
                    {
                        da=false;
                    }
                }
                sort(cene.begin(),cene.end());
                res+=cene[0];
            }
            else
            {
                for(int j=0;j<cycle.size();j++)
                {
                    visited[cycle[j]]=2;
                }
            }
        }
    }
    printf("%i\n",res);
    return 0;
}