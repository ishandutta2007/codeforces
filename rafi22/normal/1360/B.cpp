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
        int n,mini=1000000007;
        cin>>n;
        int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        sort(tab,tab+n);
        for(int i=0;i<n-1;i++)
        {
            mini=min(mini,tab[i+1]-tab[i]);
        }
        cout<<mini<<endl;
    }
    return 0;
}