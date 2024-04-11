#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
int last[nax];
int first[nax];

int main()
{
    int n,k; cin>>n>>k;
    int * a=new int[k+1];
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=n;i++) last[i]=-1;
    for(int i=1;i<=n;i++) first[i]=-1;
    for(int i=1;i<=k;i++)
    {
        last[a[i]]=i;
        if(first[a[i]]==-1) first[a[i]]=i;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int start=i;
            int koniec=i+j;
            if(koniec<1 || koniec>n) continue;
            if(start==koniec)
            {
                if(first[start]==-1) res++;
                continue;
            }
            else
            {
                if(first[start]==-1 || first[koniec]==-1 || first[start]>=last[koniec]) res++;
            }
        }
    }
    cout<<res;
    return 0;
}