#include <bits/stdc++.h>
using namespace std;
long long a[105],b[105];
vector<long long> tt;
int main(void)
{
    long long x,y,l,r;
    scanf("%I64d %I64d %I64d %I64d",&x,&y,&l,&r);
    a[0] = b[0] = 1;
    int cnt1 = 1,cnt2 = 1;
    while(r/x>=a[cnt1-1])
    {
        a[cnt1] = a[cnt1-1]*x;
        cnt1++;
    }
    while(r/y>=b[cnt2-1])
    {
        b[cnt2] = b[cnt2-1]*y;
        cnt2++;
    }
    for(int i=0;i<cnt1;i++)
    {
        for(int j=0;j<cnt2;j++)
        {
            if(a[i]+b[j]>=l && a[i]+b[j]<=r)
                tt.push_back(a[i]+b[j]);
        }
    }
    sort(tt.begin(),tt.end());
    long long ans = 0;
    if(tt.size())
        ans = max(tt[0]-l,r-tt[tt.size()-1]);
    else
        ans = r-l+1;
    for(unsigned int i = 0;i<tt.size();i++)
    {
        ans = max(tt[i]-l-1,ans);
        l = tt[i];
    }
    printf("%I64d\n",ans);
    return 0;
}