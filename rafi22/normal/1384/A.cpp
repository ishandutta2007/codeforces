#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        char zero='b';
        string last="",act="";
        for(int i=0;i<54;i++) last+='a';
        cout<<last<<endl;
        for(int i=1;i<n;i++)
        {
            act="";
            for(int j=0;j<tab[i-1];j++) act+=last[j];
            if(tab[i]>tab[i-1])
            {
                for(int j=0;j<tab[i]-tab[i-1];j++) act+=zero;
                if(zero=='z') zero='a';
                else zero++;
            }
            if(act.size()==0)
            {
                act+=zero;
                if(zero=='z') zero='a';
                else zero++;
            }
            cout<<act<<endl;
            last=act;
        }
        for(int j=0;j<tab[n-1];j++) cout<<last[j];
        if(tab[n-1]==0) cout<<zero;
        cout<<endl;
    }


    return 0;
}