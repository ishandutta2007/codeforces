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
        long long n,k,it;
        cin>>n>>k;
        long long tab[n],cnt=0,c;
        long tab1[k];
        for(long long i=0;i<n;i++) cin>>tab[i];
        for(long long i=0;i<k;i++)
        {
            cin>>tab1[i];
            if(tab1[i]==1) cnt++;
        }
        c=cnt;
        sort(tab,tab+n);
        sort(tab1,tab1+k,greater<long long>());
        long long ans=0;
        it=n-1;
        for(long long i=0;i<k;i++)
        {
            if(c>0)
            {
                ans+=2*tab[it];
                c--;
            }
            else ans+=tab[it];
            it--;
        }
        it=0;
        for(long long i=0;i<k-cnt;i++)
        {
            ans+=tab[it];
            it+=tab1[i]-1;
        }
        cout<<ans<<endl;
    }



    return 0;
}