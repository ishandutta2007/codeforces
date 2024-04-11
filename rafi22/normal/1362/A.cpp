#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        if(b<a) swap(a,b);
        if(a==b) cout<<0<<endl;
        else if(a/b%2==0)
        {
            long long cnt=0;
            bool ok=0;
            while(a!=b)
            {
                if(b/a%2==1)
                {
                    ok=1;
                    break;
                }
                if(b/a>=8) a*=8;
                else if(b/a>=4) a*=4;
                else if(b/a>=2) a*=2;
                cnt++;

            }
            if(ok) cout<<-1<<endl;
            else cout<<cnt<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}