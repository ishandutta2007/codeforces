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

const bool multi=0;

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
        int n,h,m,k,a,b,mn=inf,ans=0;
        cin>>n>>h>>m>>k;
        vector<pair<int,int>>vec;
        int it1=0,it2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            vec.pb({b,i});
            vec.pb({b+m,i});
        }
        sort(vec.begin(),vec.end());
        deque<pair<int,int>>Q1,Q2;
        int t=m;
        while(it1<sz(vec)&&vec[it1].st<=t-k) it1++;
        while(it2<sz(vec)&&vec[it2].st<=t+m/2-k) it2++;
        while(true)
        {
            //cout<<t<<" "<<it1<<" "<<it2<<endl;
            while(it1<sz(vec)&&vec[it1].st<t) Q1.pb(vec[it1++]);
            while(it2<sz(vec)&&vec[it2].st<t+m/2) Q2.pb(vec[it2++]);
            while(sz(Q1)>0&&Q1[0].st<=t-k) Q1.pop_front();
            while(sz(Q2)>0&&Q2[0].st<=t+m/2-k) Q2.pop_front();
            if(sz(Q1)+sz(Q2)<mn)
            {
                mn=sz(Q1)+sz(Q2);
                ans=t;
            }
            int nx=inf;
            if(sz(Q1)>0) nx=min(nx,Q1[0].st+k);
            if(sz(Q2)>0) nx=min(nx,Q2[0].st+k-m/2);
            if(it1<sz(vec)) nx=min(nx,vec[it1].st+1);
            if(it2<sz(vec)) nx=min(nx,vec[it2].st+1-m/2);
            if(nx==inf||nx>=m+m/2) break;
            t=nx;
        }
        cout<<mn<<" "<<ans-m<<endl;
        for(auto x:vec)
        {
            if((x.st>ans-k&&x.st<ans)||(x.st>ans+m/2-k&&x.st<ans+m/2)) cout<<x.nd<<" ";
        }
    }

    return 0;
}