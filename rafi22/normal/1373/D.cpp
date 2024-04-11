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
        long long n;
        cin>>n;
        long long tab[n],res=0;
        for(long long i=0;i<n;i++) cin>>tab[i];
        for(long long i=0;i<n;i+=2) res+=tab[i];
        long long act=0,maxi=0;
        for(long long i=0;i<n;i+=2)
        {
            if(i+1==n) break;
            act-=tab[i];
            act+=tab[i+1];
            if(act<0) act=0;
            maxi=max(act,maxi);
        }
        act=0;
        for(long long i=1;i<n;i+=2)
        {
            if(i+1==n) break;
            act+=tab[i];
            act-=tab[i+1];
            if(act<0) act=0;
            maxi=max(maxi,act);
        }
        cout<<res+maxi<<endl;
    }


    return 0;
}