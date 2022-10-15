#include<bits/stdc++.h>
using namespace std;
struct S
{
    int l,r;
} a[200010];
map<int,map<int,int> >mp;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>a[i].l>>a[i].r;
        mp[a[i].l][a[i].r]=1;
        mp[a[i].r][a[i].l]=1;
    }
    int fll=0;
    for (i=1;i<=sqrt(n+0.5);i++)
    {
        if (n%i==0)
        {
            int c=i;
            int fl=0;
            for (j=0;j<m;j++)
            {
                int x=(a[j].l+c)%n,y=(a[j].r+c)%n;
                if (x==0)x=n;
                if (y==0)y=n;
                if (mp[x][y]==0)
                {
                    fl=1;
                    break;
                }
            }
            if (fl==0) {
                fll=1;
                break;
            }
            if (i==1) continue;
            c=n/i;
            fl=0;
            for (j=0;j<m;j++)
            {
                int x=(a[j].l+c)%n,y=(a[j].r+c)%n;
                if (x==0)x=n;
                if (y==0)y=n;
                if (mp[x][y]==0)
                {
                    fl=1;
                    break;
                }
            }
            if (fl==0) {
                fll=1;
                break;
            }
        }
        if (fll==1) break;
    }
    if (fll==1) cout<<"YES";
    else cout<<"NO";
}