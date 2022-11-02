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

const bool multi=0;

const int N=100007,pot=1<<17;

struct S
{
    int l,r;
    int d[2][2];
};

int X[N][2];
int Y[N][2];
int pX[N][2];
int pY[N][2];
int n;

S seg[2*pot+7];

S Merge(S L,S R)
{
    if(L.l==0) return R;
    if(R.l==0) return L;
    S x;
    x.l=L.l;
    x.r=R.r;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            x.d[i][j]=inf;
            for(int l=0;l<2;l++)
            {
                for(int k=0;k<2;k++)
                {
                    int c=abs(pX[L.r][l]-X[L.r+1][k])+abs(pY[L.r][l]-Y[L.r+1][k]);
                    x.d[i][j]=min(x.d[i][j],L.d[i][l]+R.d[k][j]+c);
                }
            }
        }
    }
    return x;
}

S que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b)
    {
        S x;
        x.l=0;
        x.r=0;
        return x;
    }
    return Merge(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            cin>>X[i][0]>>Y[i][0]>>X[i][1]>>Y[i][1];
            pX[i][0]=X[i][0]+1;
            pY[i][0]=Y[i][0];
            pX[i][1]=X[i][1];
            pY[i][1]=Y[i][1]+1;
        }
        for(int i=2;i<=n;i++)
        {
            seg[i+pot-1].d[0][1]=inf;
            seg[i+pot-1].d[1][0]=inf;
            seg[i+pot-1].d[0][0]=1;
            seg[i+pot-1].d[1][1]=1;
            seg[i+pot-1].l=i-1;
            seg[i+pot-1].r=i;
        }
        for(int i=pot-1;i>0;i--) seg[i]=Merge(seg[2*i],seg[2*i+1]);
       /* S x=que(1,2,4,1,pot);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
               // int c=abs(x1-X[l+1][i])+abs(y1-Y[l+1][i])+abs(x2-pX[r][j])+abs(y2-pY[r][j]);
                cout<<x.d[i][j]<<" ";
              //  ans=min(ans,x.d[i][j]+c);
            }
            cout<<endl;
        }*/
        int q;
        cin>>q;
        while(q--)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(max(x1,y1)>max(x2,y2))
            {
                swap(x1,x2);
                swap(y1,y2);
            }
            int l=max(x1,y1),r=max(x2,y2);
            if(l==r) cout<<abs(x1-x2)+abs(y1-y2)<<endl;
            else
            {
                S x=que(1,l+1,r,1,pot);
                int ans=inf;
                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<2;j++)
                    {
                        int c=abs(x1-X[l+1][i])+abs(y1-Y[l+1][i])+abs(x2-pX[r][j])+abs(y2-pY[r][j]);
                       // cout<<x.d[i][j]<<" ";
                        ans=min(ans,x.d[i][j]+c);
                    }
                 //   cout<<endl;
                }
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}