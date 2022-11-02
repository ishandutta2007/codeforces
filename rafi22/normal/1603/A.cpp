#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[100007];
int pos[100007];

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
        set<int>S;
        S.insert(0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[i]=i+1;
            S.insert(i);
        }
        while(sz(S)>0)
        {
            bool lol=0;
            for(set<int>::iterator it=--S.end();;it--)
            {
                int i=*it;
                if(i==0) break;
                if(a[i]%pos[i]!=0)
                {
                    lol=1;
                    for(set<int>::iterator it1=it;it1!=S.end();it1++) pos[*it1]--;
                    S.erase(it);
                    break;
                }
            }
            if(!lol) break;
        }
        if(sz(S)==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}