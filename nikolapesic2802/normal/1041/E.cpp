#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    vector<int> cnt(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        if(a==n)
            cnt[b]++;
        else
            if(b==n)
                cnt[a]++;
            else
            {
                printf("NO\n");
                return 0;
            }

    }
    if(cnt[n]>0)
    {
        printf("NO\n");
        return 0;
    }
    vector<int> nula;
    vector<pair<int,int> > construct,edges;
    for(int i=1;i<n;i++)
    {
        if(cnt[i]==0)
            nula.pb(i);
        if(cnt[n-i]>0)
            construct.pb({n-i,cnt[n-i]});
    }
    int last=n;
    for(auto p:construct)
    {
        int i=p.first,c=p.second-1;
        while(c--)
        {
            if(nula.empty()||nula.back()>i)
            {
                printf("NO\n");
                return 0;
            }
            edges.pb({nula.back(),last});
            last=nula.back();
            nula.pop_back();
        }
        edges.pb({last,i});
        last=i;
    }
    if(nula.size())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(auto p:edges)
    {
        printf("%i %i\n",p.first,p.second);
    }
    return 0;
}