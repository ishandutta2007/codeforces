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
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;
struct point{int x,y,t;};
bool cmp(point L,point R) {return L.x<R.x;};
bool cmp1(point L,point R) {return L.y<R.y;};
point p[100007];
point p1[100007];
int ans,n;

void case1(vector<int>o)
{
    int l=1,r=n/3,sr;
    while(l<=r)
    {
        sr=(l+r)/2;
        int last=-inf;
        bool ok=1;
        for(int i=0;i<3;i++)
        {
            bool is=0;
            int ile=0;
            for(int j=1;j<=n;j++)
            {
                if(p[j].t==o[i]&&p[j].x>last) ile++;
                if(ile==sr)
                {
                    is=1;
                    last=p[j].x;
                    break;
                }
            }
            ok&=is;
        }
        if(ok)
        {
            ans=max(ans,3*sr);
            l=sr+1;
        }
        else r=sr-1;
    }
}
void case2(vector<int>o)
{
    int l=1,r=n/3,sr;
    while(l<=r)
    {
        sr=(l+r)/2;
        bool ok=0;
        int ile=0;
        int L=inf;
        for(int j=1;j<=n;j++)
        {
            if(p1[j].t==o[0]) ile++;
            if(ile==sr)
            {
                ok=1;
                L=p1[j].y;
                break;
            }
        }
        int last=-inf;
        for(int i=1;i<3;i++)
        {
            bool is=0;
            ile=0;
            for(int j=1;j<=n;j++)
            {
                if(p[j].t==o[i]&&p[j].x>last&&p[j].y>L) ile++;
                if(ile==sr)
                {
                    is=1;
                    last=p[j].x;
                    break;
                }
            }
            ok&=is;
        }
        if(ok)
        {
            ans=max(ans,3*sr);
            l=sr+1;
        }
        else r=sr-1;
    }
}

void run1()
{
    vector<int>o={1,2,3};
    while(true)
    {
        case1(o);
        if(!next_permutation(all(o))) break;
    }
}
void run2()
{
    vector<int>o={1,2,3};
    while(true)
    {
        case2(o);
        if(!next_permutation(all(o))) break;
    }
}
void rev()
{
    for(int i=1;i<=n;i++) p[i].y=-p[i].y;
    for(int i=1;i<=n;i++) p1[i].y=-p1[i].y;
    sort(p+1,p+n+1,cmp);
    sort(p1+1,p1+n+1,cmp1);
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
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].x>>p[i].y>>p[i].t;
            p1[i]=p[i];
        }
        sort(p+1,p+n+1,cmp);
        sort(p1+1,p1+n+1,cmp1);
       // for(int i=1;i<=n;i++) cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].t<<endl;
        run1();
        run2();
        rev();
        run2();
        rev();
        for(int i=1;i<=n;i++) swap(p[i].x,p[i].y);
        for(int i=1;i<=n;i++) swap(p1[i].x,p1[i].y);
        sort(p+1,p+n+1,cmp);
        sort(p1+1,p1+n+1,cmp1);
        run1();
        run2();
        rev();
        run2();
        cout<<ans;
    }

    return 0;
}