#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,even=0,odd=0,par=0;
        cin>>n;
        int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        sort(tab,tab+n);
        for(int i=0;i<n-1;i++)
        {
            if(tab[i]%2==0) even++;
            else odd++;
            if(tab[i+1]-tab[i]==1) par++;
        }
        if(tab[n-1]%2==0) even++;
        else odd++;
        if(odd%2==0&&even%2==0) cout<<"YES"<<endl;
        else if(par>0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}