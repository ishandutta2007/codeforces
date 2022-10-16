#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

void test()
{
    int n;
    scanf("%i",&n);
    vector<vector<int> > graf(n+1);
    vector<int> unutra(n+1),unutra2(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    int k1;
    scanf("%i",&k1);
    for(int i=0;i<k1;i++)
    {
        int a;
        scanf("%i",&a);
        unutra[a]=1;
    }
    int prvi;
    int k2;
    scanf("%i",&k2);
    for(int i=0;i<k2;i++)
    {
        int a;
        scanf("%i",&a);
        prvi=a;
        unutra2[a]=1;
    }
    printf("B %i\n",prvi);
    fflush(stdout);
    int start;
    scanf("%i",&start);
    if(start==-1)
        exit(0);
    vector<int> visited(n+1);
    queue<int> q;
    q.push(start);
    visited[start]=1;
    int najblizi;
    while(true)
    {
        int tr=q.front();
        //printf("%i %i\n",tr,unutra[tr]);
        if(unutra[tr])
        {
            najblizi=tr;
            break;
        }
        q.pop();
        for(auto p:graf[tr])
        {
            if(!visited[p])
            {
                visited[p]=1;
                q.push(p);
            }
        }
    }
    printf("A %i\n",najblizi);
    fflush(stdout);
    int s;
    scanf("%i",&s);
    if(s==-1)
        exit(0);
    if(unutra2[s])
    {
        printf("C %i\n",najblizi);
        fflush(stdout);
    }
    else
    {
        printf("C -1\n");
        fflush(stdout);
    }
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
        test();
    return 0;
}