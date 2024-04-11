#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int a[200007];
int seg[4*200007][4];
int lazy[4*200007][4];
int pot=1;

void push(int v,int c)
{
    lazy[2*v][c]+=lazy[v][c];
    lazy[2*v+1][c]+=lazy[v][c];
    seg[2*v][c]+=lazy[v][c];
    seg[2*v+1][c]+=lazy[v][c];
    lazy[v][c]=0;
}

void ins(int v,int a,int b,int l,int r,int c,int x)
{
    if(r<a||l>b) return ;
    if(l>=a&&b>=r)
    {
        //cout<<l<<" "<<r<<endl;
        seg[v][c]+=x;
        lazy[v][c]+=x;
        return ;
    }
    push(v,c);
    ins(2*v,a,b,l,(l+r)/2,c,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,c,x);
    if(c%2==0) seg[v][c]=min(seg[2*v][c],seg[2*v+1][c]);
    else seg[v][c]=max(seg[2*v][c],seg[2*v+1][c]);
}

int que(int v,int a,int b,int l,int r,int c)
{
    if(r<a||l>b)
    {
        if(c%2==0) return inf;
        else return -inf;
    }
    if(l>=a&&b>=r) return seg[v][c];
    push(v,c);
    if(c%2==0) return min(que(2*v,a,b,l,(l+r)/2,c),que(2*v+1,a,b,(l+r)/2+1,r,c));
    else return max(que(2*v,a,b,l,(l+r)/2,c),que(2*v+1,a,b,(l+r)/2+1,r,c));
}

vector<int>vec[200007];
int ans[200007];


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
        while(pot<n+1) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vec[a[i]].pb(i);
            seg[i+pot][0]=i;
            seg[i+pot][1]=i;
            seg[i+pot][2]=i;
            seg[i+pot][3]=i;
        }
        for(int i=pot-1;i>0;i--)
        {
            seg[i][0]=min(seg[2*i][0],seg[2*i+1][0]);
            seg[i][1]=max(seg[2*i][1],seg[2*i+1][1]);
            seg[i][2]=min(seg[2*i][2],seg[2*i+1][2]);
            seg[i][3]=max(seg[2*i][3],seg[2*i+1][3]);
        }
        for(int j=1;j<=200000;j++)
        {
            for(auto i:vec[j])
            {
                ins(1,i+1,n+1,1,pot,2,-2);
                ins(1,i+1,n+1,1,pot,3,-2);
            }
            for(auto i:vec[j])
            {
                int x=-(que(1,i+1,n+1,1,pot,2)-que(1,1,i,1,pot,3));
                if(abs(x%2)==1) x=x/2;
                else x=x/2-1;
                ans[i]=max(ans[i],x);
                x=que(1,i+1,n+1,1,pot,1)-que(1,1,i,1,pot,0);
               // cout<<x<<endl;
                if(abs(x%2)==1) x=x/2;
                else x=x/2;
                ans[i]=max(ans[i],x);
            }
            for(auto i:vec[j])
            {
                ins(1,i+1,n+1,1,pot,0,-2);
                ins(1,i+1,n+1,1,pot,1,-2);
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}