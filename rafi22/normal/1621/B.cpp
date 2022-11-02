#include <bits/stdc++.h>

#define int long long
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

map<int,int> mnL;
map<int,int> mnR;

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
        mnL.clear();
        mnR.clear();
        int L=inf,R=-inf;
        set<pair<pair<int,int>,int>>S;
        S.insert({{inf,inf},inf});
        for(int i=1;i<=n;i++)
        {
            int l,r,c;
            cin>>l>>r>>c;
            L=min(L,l);
            R=max(R,r);
            S.insert({{l,r},c});
            if(mnL[l]==0) mnL[l]=c;
            else mnL[l]=min(mnL[l],c);
            if(mnR[r]==0) mnR[r]=c;
            else mnR[r]=min(mnR[r],c);
            pair<pair<int,int>,int>p=*S.lower_bound({{L,R},0});
            if(p.st.st==L&&p.st.nd==R) cout<<min(p.nd,mnL[L]+mnR[R])<<endl;
            else cout<<mnL[L]+mnR[R]<<endl;
        }
    }

    return 0;
}