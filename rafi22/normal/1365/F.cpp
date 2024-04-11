#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        bool is=1;
        if(n%2==1)
        {
            if(a[n/2]!=b[n/2])
            {
                is=0;
            }
        }
        for(int i=0; i<n/2; i++)
        {
            bool ok=0;
            for(int j=0; j<n/2; j++)
            {
                if((b[j]==a[i]&&b[n-j-1]==a[n-i-1])||(b[j]==a[n-i-1]&&b[n-j-1]==a[i]))
                {
                    ok=1;
                    b[j]=-1;
                    b[n-j-1]=-1;
                    break;
                }
            }
            if(!ok) is=0;
        }
        if(is) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}