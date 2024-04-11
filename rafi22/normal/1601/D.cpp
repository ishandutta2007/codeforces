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

const bool multi=0;

const int N=500007;

map<int,int>nr;
int l[N],r[N];
int ile[N];
int BIT[2*N];
int DP[N];
int p[N];
int que(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=BIT[x];
	return s;
}
void ins(int x,int s) {
	for (;x<=1000000;x+=x&-x) BIT[x]+=s;
}

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
        int n,d;
        cin>>n>>d;
        set<int>S;
        S.insert(d);
        for(int i=1;i<=n;i++)
        {
            cin>>l[i]>>r[i];
            S.insert(l[i]);
            S.insert(r[i]);
        }
        int it=0;
        for(auto x:S) nr[x]=++it;
        d=nr[d];
        vector<pair<int,int>>V;
        vector<pair<int,int>>V1;
        for(int i=1;i<=n;i++)
        {
            l[i]=nr[l[i]];
            r[i]=nr[r[i]];
            ile[i]=1;
            if(r[i]<l[i])
            {
                ins(r[i],1);
                V.pb({l[i],i});
                if(l[i]>=d) V1.pb({r[i],0});
            }
            else
            {
                V.pb({r[i],-i});
                if(l[i]>=d)
                {
                    if(l[i]==r[i]) V1.pb({r[i],0});
                    else
                    {
                        V1.pb({l[i],i});
                        V1.pb({r[i],-i});
                    }
                   // cout<<l[i]<<" "<<r[i]<<endl;
                }
            }
        }
        sort(all(V));
        for(auto x:V)
        {
            if(x.nd>0) ins(r[x.nd],-1);
            else ile[-x.nd]+=max(0,que(r[-x.nd]-1)-que(l[-x.nd]));
        }
       /* for(int i=1;i<=n;i++) cout<<ile[i]<<" ";
        cout<<endl;*/
        sort(all(V1));
        it=0;
        for(auto x:V1)
        {
            if(x.nd<0)
            {
                it++;
                DP[it]=max(DP[it-1],DP[p[-x.nd]]+ile[-x.nd]);
            }
            else if(x.nd==0)
            {
                it++;
                DP[it]=DP[it-1]+1;
            }
            else p[x.nd]=it;
        }
        cout<<DP[it];
    }

    return 0;
}