#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int M=20005;
int d[M];
vector<vector<int> > graf(M);
void add(int a,int b)
{
    graf[a].pb(b);
}
int main()
{
    add(1,2);
    for(int i=2;i<M;i++)
    {
        if(i<10000)
        {
            add(i,2*i);
        }
        add(i,i-1);
    }
    int n,m;
    scanf("%i %i",&n,&m);
    if(n==m)
    {
        printf("0\n");
        return 0;
    }
    queue<int> q;
    d[n]=1;
    q.push(n);
    while(!q.empty())
    {
        //printf("Usao za %i\n",q.front());
        int tr=q.front();
        q.pop();
        for(int i=0;i<graf[tr].size();i++)
        {
            int sl=graf[tr][i];
            if(sl==m)
            {
                printf("%i\n",d[tr]);
                return 0;
            }
            if(d[sl]==0)
            {
                d[sl]=d[tr]+1;
                q.push(sl);
            }
        }
    }
}