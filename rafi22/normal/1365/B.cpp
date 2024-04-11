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
        int n;
        cin>>n;
        int tab[n];
        int tab1[n];
        char znak[n];
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            tab1[i]=tab[i];
        }
        sort(tab1,tab1+n);
        for(int i=0;i<n;i++) cin>>znak[i];
        bool j0=0,j1=0,s=1;
        for(int i=0;i<n;i++)
        {
            if(tab[i]!=tab1[i]) s=0;
            if(znak[i]=='0') j0=1;
            if(znak[i]=='1') j1=1;
        }
        if(j0&&j1||s) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}