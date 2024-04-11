#include <bits/stdc++.h>
using namespace std;
long long dx[100001],dy[100001],n,m,i,j,k,t,t1,u,v,a,b,res=0;
map<long long,long long> buc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        res=0;
        buc.clear();
        for (i=1;i<=n;i++)
        {
            cin>>u>>v>>a>>b;
            dx[i]=a-u;
            dy[i]=b-v;
            if ((dx[i])and(dy[i]))
            {
                u=__gcd(abs(dx[i]),abs(dy[i]));
                dx[i]/=u;
                dy[i]/=u;
            }
            else if (!dx[i]) dy[i]/=abs(dy[i]);
            else if (!dy[i]) dx[i]/=abs(dx[i]);
         //   cout<<dx[i]<<' '<<dy[i]<<endl;
            buc[dx[i]*3000000000+dy[i]]++;
        }
        for (i=1;i<=n;i++)
        {
            res+=buc[-dx[i]*3000000000-dy[i]];
        }
        res/=2;
        cout<<res<<endl;
    }
}