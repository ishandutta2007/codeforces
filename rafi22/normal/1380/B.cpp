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

int tab[1007];

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
        string str;
        cin>>str;
        int r=0,p=0,s=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='R') r++;
            else if(str[i]=='P') p++;
            else s++;
        }
        if(r>=p&&r>=s) for(int i=0;i<str.size();i++) cout<<'P';
        else if(p>=r&&p>=s) for(int i=0;i<str.size();i++) cout<<'S';
        else if(s>=r&&s>=p) for(int i=0;i<str.size();i++) cout<<'R';
        cout<<endl;
    }

    return 0;
}