#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
        int n,t,last=0;
        cin>>n;
        ordered_set S;
        ordered_set::iterator it;
        S.insert(inf);
        S.insert(-inf);
        for(int x=1;x<=n;x++)
        {
            cin>>t;
            int l=1,r=sz(S)-1,sr,L,R;
            while(l<=r)
            {
                sr=(l+r)/2;
                it=S.find_by_order(sr);
                int i=*it,j=*(--it);
                if(i-x+sz(S)-sr<t) l=sr+1;
                else if(j-x+sz(S)-sr+1>=t) r=sr-1;
                else
                {
                    L=i-(i-x+sz(S)-sr-t);
                    r=sr-1;
                }
            }
            l=1,r=sz(S)-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                it=S.find_by_order(sr);
                int i=*it,j=*(--it);
                if(i-x+sz(S)-sr<t) l=sr+1;
                else if(j-x+sz(S)-sr+1>t) r=sr-1;
                else
                {
                    R=i-(i-x+sz(S)-sr-t);
                    l=sr+1;
                }
            }
            S.insert(R);
            S.insert(L-1);
            int k,c;
            cin>>k;
            while(k--)
            {
                cin>>c;
                c=(c+last)%1000000001;
                int ans=c-x+sz(S)-1-S.order_of_key(c);
                cout<<ans<<endl;
                last=ans;
            }
        }
    }

    return 0;
}