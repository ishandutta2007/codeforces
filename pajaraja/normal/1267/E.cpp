#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi = 1010;
vector<int> ans;
int a[maxi][maxi];
int n,m;
pair<int,int> b[maxi];

int main()
{
    cin>>n>>m;

    for (int i = 1;i<=m;i++)
        for (int  j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    for (int i=1;i<=m;i++)
        ans.pb(i);

    for (int i=1;i<n;i++)
    {
        for (int j=1;j<=m;j++)
        b[j] = {a[j][i] - a[j][n], j};

        sort(b+1, b+m+1);
        reverse(b+1, b+m+1);

        int sum = 0;
        int poz = m+1;
        for (int j=1;j<=m;j++)
        {
            sum+=b[j].first;
            if (sum<0)
            {
                poz = j;
                break;
            }
        }

        if (m - poz +1 <ans.size())
        {
            ans.clear();

            for (int j=poz;j<=m;j++)
                ans.pb(b[j].second);
        }
    }

    cout<<ans.size()<<endl;

    for (int i:ans)
        printf("%d ",i);
    printf("\n");
}