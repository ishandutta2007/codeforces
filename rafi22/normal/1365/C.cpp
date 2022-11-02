#include <bits/stdc++.h>

using namespace std;

int L[200007];
int P[200007];
int pos[200007];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        pos[a]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(i>pos[a])
        {
            P[n-i+pos[a]]++;
            L[i-pos[a]]++;
        }
        else if(i<pos[a])
        {
            L[n-pos[a]+i]++;
            P[pos[a]-i]++;
        }
        else
        {
            L[0]++;
            P[0]++;
        }
    }
    int res=0;
    for(int i=0;i<=n;i++)
    {
        res=max(res,L[i]);
        res=max(res,P[i]);
    }
    cout<<res;

    return 0;
}