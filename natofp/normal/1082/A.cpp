#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        int ans1,ans2;
        ans1=-1;
        ans2=-1;
        if(y%d==x%d) cout<<abs(x-y)/d<<endl;
        else
        {
            if(y%d==1)

            {
                ans1=0;
                ans1+=(x-1)/d;
                if((x-1)%d!=0) ans1++;
                ans1+=(y-1)/d;


            }
            if(y%d==n%d)
            {
                ans2=0;
                ans2+=(n-x)/d;
                if((n-x)%d!=0) ans2++;
                ans2+=(n-y)/d;

            }
            if(ans2==-1 || ans1==-1) cout<<max(ans1,ans2)<<endl;
            else cout<<min(ans1,ans2)<<endl;

        }
    }
    return 0;
}