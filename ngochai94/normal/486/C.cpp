#include <bits/stdc++.h>
using namespace std;
int n,p,lef,righ,ans;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n>>p;
    p--;
    if (p>=n/2) p=n-1-p;
    cin >> s;
    lef=-1;
    for (int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            lef=i;
            break;
        }
    }
    if(lef==-1) cout <<0;
    else
    {
        for (int i=n/2-1;i>-1;i--)
        {
            if(s[i]!=s[n-1-i])
            {
                righ=i;
                break;
            }
        }
        ans=min(abs(lef-p),abs(righ-p))+righ-lef;
        for (int i=lef;i<=righ;i++)
        {
            p=abs(s[i]-s[n-1-i]);
            ans+=min(p,26-p);
        }
        cout << ans;
    }
}