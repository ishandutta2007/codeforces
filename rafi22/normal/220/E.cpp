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

int a[100007];
map<int,int>mapa;

int BIT[100007][2];
int que(int x,bool b) {
	int s=0;
	for (;x;x-=x&-x) s+=BIT[x][b];
	return s;
}
void ins(int x,int s,bool b) {
	for (;x<=100000;x+=x&-x) BIT[x][b]+=s;
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
        int n,k;
        cin>>n>>k;
        set<int>S;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            S.insert(a[i]);
        }
        int it=0;
        for(auto x:S) mapa[x]=++it;
        int act=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=mapa[a[i]];
            ins(a[i],1,1);
            act+=que(100000,1)-que(a[i],1);
        }
        int p=0,ans=0;
        for(int i=2;i<=n;i++)
        {
            act-=que(100000,0)-que(a[i-1],0);
           // cout<<act<<endl;
            act-=que(a[i-1]-1,1);
            ins(a[i-1],-1,1);
            while(p+1<i)
            {
                int x=que(100000,0)-que(a[p+1],0)+que(a[p+1]-1,1);
                if(act+x>k) break;
                p++;
                act+=x;
                ins(a[p],1,0);
            }
           // cout<<act<<endl;
            //cout<<p<<" ";
            ans+=p;
        }
        cout<<ans;
    }

    return 0;
}