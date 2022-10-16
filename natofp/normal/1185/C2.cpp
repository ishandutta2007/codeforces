#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
int a[nax];
int n,m;
int ile[111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ile,0,sizeof ile);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int limit=m-a[i];
        int wyje=sum-limit;
        int res=0;
        for(int j=100;j>=1;j--)
        {
            if(wyje<=0) break;
            int t=ile[j];
            int mozna=t;
            int trzeba=wyje/j+(wyje%j!=0);
            int biore=min(mozna,trzeba);
            res+=biore;
            wyje-=j*biore;
        }
        cout<<res<<" ";
        ile[a[i]]++;
        sum+=a[i];
    }
    return 0;
}