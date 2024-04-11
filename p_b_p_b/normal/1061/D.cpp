#include<bits/stdc++.h>
#define sz 200020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
struct hh{ll t,id;bool d;}s[sz];
inline bool cmp(const hh &x,const hh &y){return x.t==y.t?x.d<y.d:x.t<y.t;}
struct hhh{ll l,r;}a[sz];
int n;
ll X,Y;
int main()
{
	file();
	ll i,x,y;
	read>>n>>X>>Y;
	for (i=1;i<=n;i++) read>>x>>y,a[i]=(hhh){x,y},s[i*2-1]=(hh){x,i,0},s[i*2]=(hh){y,i,1};
	stack<int>st;
	ll ans=0;
	sort(s+1,s+n+n+1,cmp);
	for (i=1;i<=n+n;i++)
	{
		if (s[i].d) st.push(s[i].t);
		else
		{
			y=a[s[i].id].r;
			if (st.empty()) (ans+=(X+Y*(y-s[i].t)%mod)%mod)%=mod;
			else
			{
				x=st.top();
				if (Y*(y-x)<X+Y*(y-s[i].t)) (ans+=Y*(y-x)%mod)%=mod,st.pop();
				else (ans+=(X+Y*(y-s[i].t)%mod)%mod)%=mod;
			}
		}
	}
	cout<<ans;
}