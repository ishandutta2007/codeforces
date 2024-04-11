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
        int n;
        cin>>n;
        int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        sort(tab,tab+n);
        int act=1,ile=0;
        for(int i=0;i<n;i++)
        {
            ile++;
            while(i<n-1&&tab[i]==tab[i+1])
            {
                ile++;
                i++;
            }
            if(act+ile-1>=tab[i])
            {
                act+=ile;
                ile=0;
            }
        }
        cout<<act<<endl;

    }
    return 0;
}