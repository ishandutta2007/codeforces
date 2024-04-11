#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1000000007;
struct Matrix
{
    int a[3][3];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
}M[8];
struct Event
{
    ll x;
    int a,t;
    bool operator < (const Event &t)const
    {
        return x<t.x;
    }
};
int main()
{
    for(int mask=0;mask<8;mask++)
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                M[mask].a[i][j]=(abs(i-j)<=1 && (mask>>j&1));
    int n;
    scanf("%d",&n);
    ll m;
    scanf("%lld",&m);
    vector<Event> e;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a),a--;
        ll l,r;
        scanf("%lld%lld",&l,&r),l--;
        e.push_back({l,a,1});
        e.push_back({r,a,-1});
    }
    sort(e.begin(),e.end());
    Matrix A;
    A.init();
    int cnt[3]={0,0,0};
    ll las=1;
    for(int i=0;i<(int)e.size();i++)
    {
        ll now=e[i].x;
        if(now>las)
        {
            int mask=0;
            for(int j=0;j<3;j++)
                mask|=(cnt[j]==0)<<j;
            A=A*(M[mask]^(now-las));
        }
        cnt[e[i].a]+=e[i].t;
        las=now;
    }
    A=A*(M[7]^(m-las));
    printf("%d\n",A.a[1][1]);
    return 0;
}