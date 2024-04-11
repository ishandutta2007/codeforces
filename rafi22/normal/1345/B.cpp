#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
   for(int i=0;i<t;i++)
    {
        long long n,ans=0,act=2;
        cin>>n;
        while(n>1)
        {
            act=2;
            for(long long i=2;i<=100000;i++)
            {
                if(act+2*i+(i-1)<=n)
                    act+=2*i+(i-1);
                else
                {
                    n-=act;
                    ans++;
                    break;
                }

            }
         }
         cout<<ans<<endl;


    }

    return 0;
}