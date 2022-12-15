#include <bits/stdc++.h>
using namespace std;
int n,check;
long long l,r,ans,mark;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    while (n--)
    {
        cin>>l>>r;
        ans=0;
        if (l==r)
        {
            cout <<l<<endl;
            continue;
        }
        for (long long i=63;i>-1;i--)
        {
            if ((l&(1ll<<i))!=0 && (r&(1ll<<i))!=0) ans+=(1ll<<i);
            else if ((r&(1ll<<i))!=0)
            {
                mark=i;
                break;
            }
        }
        check=1;
        for (int i=mark-1;i>-1;i--) if((r&(1ll<<i))==0)
        {
            check=0;
            break;
        }
        if (check)
        {
            for (int i=mark;i>-1;i--) ans+=(1ll<<i);
            cout <<ans<<endl;
        }
        else
        {
            for (int i=mark-1;i>-1;i--)
            {
                ans+=(1ll<<i);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}