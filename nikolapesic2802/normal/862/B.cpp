#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=100005;
vector<int> graf[N];
int p[N];
int br[3];
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    p[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int tr=q.front();
        q.pop();
        for(int i=0;i<graf[tr].size();i++)
        {
            int sl=graf[tr][i];
            if(p[sl]==0)
            {
                q.push(sl);
                if(p[tr]==1)
                    p[sl]=2;
                else
                    p[sl]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        br[p[i]]++;
    printf("%lld\n",(ll)br[1]*br[2]-n+1);
    return 0;
}