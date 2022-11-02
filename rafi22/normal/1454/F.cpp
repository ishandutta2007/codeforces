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

int seg[600007];
int mx[200007];

int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&r<=b) return seg[v];
    if(r<a||l>b) return inf;
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,a=-1,b=-1,c=-1,act=0,pot=1;
        cin>>n;
        while(pot<n) pot*=2;
        for(int i=0;i<=2*pot;i++) seg[i]=inf;
        for(int i=1;i<=n;i++) cin>>seg[pot+i-1];
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        mx[n+1]=0;
        for(int i=n;i>0;i--) mx[i]=max(mx[i+1],seg[pot+i-1]);
        for(int i=1;i<=n;i++)
        {
            act=max(act,seg[i+pot-1]);
            int l=i+1,p=n-1,sr;
            while(l<=p)
            {
                sr=(l+p)/2;
                int mn=que(1,i+1,sr,1,pot);
                if(act==mx[sr+1])
                {
                    if(mn==mx[sr+1])
                    {
                        a=i,b=sr-i,c=n-sr;
                        break;
                    }
                    else if(mn>mx[sr+1]) l=sr+1;
                    else p=sr-1;
                }
                else if(act>mx[sr+1]) p=sr-1;
                else l=sr+1;
            }

        }
        if(a==-1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<a<<" "<<b<<" "<<c<<endl;
    }

    return 0;
}