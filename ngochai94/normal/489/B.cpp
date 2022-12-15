#include <bits/stdc++.h>
using namespace std;

int lis[3001];
int n,m,boy[101],girl[101],ans,j;
int main()
{
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=0;i<n;i++) cin>>boy[i];
    cin>>m;
    for (int j=0;j<m;j++) cin>>girl[j];
    sort(boy,boy+n);
    sort(girl,girl+m);
    ans=0;
    j=0;
    for (int i=0;i<n;i++)
    {
        while (girl[j]<boy[i]-1)
        {
            j++;
            if (j==m) break;
        }
        if (j==m) break;
        if (girl[j]<=boy[i]+1)
        {
            ans++;
            j++;
        }
        if (j==m) break;
    }
    cout << ans;
    return 0;
}