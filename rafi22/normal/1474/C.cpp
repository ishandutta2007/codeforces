#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[2007];
pair<int,int>ans[2007];


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
        multiset<int>s;
        for(int i=1;i<=2*n;i++) cin>>a[i];
        sort(a+1,a+2*n+1);
        bool ok=0;
        for(int j=1;j<2*n;j++)
        {
            s.clear();
            for(int i=1;i<=2*n;i++) s.insert(a[i]);
            ans[1].st=*(--s.end());
            ans[1].nd=a[j];
            s.erase(s.find(ans[1].st));
            s.erase(s.find(ans[1].nd));
            bool zle=0;
            for(int i=2; i<=n; i++)
            {
                ans[i].st=*(--s.end());
                s.erase(s.find(ans[i].st));
                if(!s.count(ans[i-1].st-ans[i].st))
                {
                    zle=1;
                    break;
                }
                ans[i].nd=ans[i-1].st-ans[i].st;
                s.erase(s.find(ans[i-1].st-ans[i].st));
            }

            if(zle) continue;
            cout<<"YES"<<endl;
            cout<<ans[1].st+ans[1].nd<<endl;
            for(int i=1; i<=n; i++) cout<<ans[i].st<<" "<<ans[i].nd<<endl;
            ok=1;
            break;
        }
        if(!ok) cout<<"NO"<<endl;
    }

    return 0;
}