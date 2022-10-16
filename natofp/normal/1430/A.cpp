#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        bool ok = false;
        for(int i=0;i<=333;i++)
        {
            for(int j=0;j<=1000 - i * 3;j++)
            {
                int cur = i * 3 + j * 5;
                if(cur > n) break;
                if(cur <= n && (n-cur)%7==0)
                {
                    cout<<i<<" "<<j<<" "<<(n-cur)/7<<"\n";
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout<<"-1"<<"\n";
    }

    return 0;
}