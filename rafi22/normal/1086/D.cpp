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

int a[200007];
set<int>S[3];
int n;

int BIT[200007][3];
int que(int x,int c) {
	int s=0;
	if(x<=0) return 0;
	for (;x;x-=x&-x) s+=BIT[x][c];
	return s;
}
void ins(int x,int s,int c) {
	for (;x<=200000;x+=x&-x) BIT[x][c]+=s;
}

void upd(int v,int x)
{
    if(a[v]!=-1)
    {
        S[a[v]].erase(v);
        ins(v,-1,a[v]);
    }
    a[v]=x;
    S[a[v]].insert(v);
    ins(v,1,a[v]);
}
int id[200];
int cnt(int x)
{
    int y=(x-1+3)%3,z=(x+1)%3;
    if(sz(S[z])==0) return 0;
    if(sz(S[y])==0) return que(n,x);
    int Y,Z,l=0,r=0,L=0,R=0;
    Y=*S[y].begin(),Z=*S[z].begin();
    if(Z<Y)
    {
        l=Z;
        r=Y;
    }
    Y=*--S[y].end(),Z=*--S[z].end();
    if(Z>Y)
    {
        L=max(r+1,Y);
        R=Z;
    }
    return max(0LL,que(r,x)-que(l-1,x))+max(0LL,que(R,x)-que(L-1,x));
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
        id['R']=0;
        id['P']=1;
        id['S']=2;
        int q,x;
        cin>>n>>q;
        for(int i=1;i<=n;i++) a[i]=-1;
        char c;
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            upd(i,id[c]);
        }
        cout<<n-cnt(0)-cnt(1)-cnt(2)<<endl;
        while(q--)
        {
            cin>>x>>c;
            upd(x,id[c]);
            cout<<n-cnt(0)-cnt(1)-cnt(2)<<endl;
        }
    }

    return 0;
}