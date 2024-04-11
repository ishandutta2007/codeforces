#include<bits/stdc++.h>
#define sz 201010
#define mod (int)(1e9+7)
#define int ll
using namespace std;
typedef long long ll;
struct FastIO
{//lalalala
    inline FastIO& operator>>(int& x)
    {//lalalala
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();//lalalala
        return x=(f?-x:x),*this;//lalalala
    }//lalalala
}read;//lalalala
void file()
{//lalalala
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}//lalalala
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,T;//lalalala
ll sum[sz];//lalalala
struct hh{ll s;int id;}a[sz];
inline bool cmp(const hh &x,const hh &y){return x.s<y.s;}
int tr[sz<<1];
#define lb(x) (x&(-x))
void add(int x){while (x<=n+1+1) tr[x]++,x+=lb(x);}//lalalala
int query(int x){int ret=0;while (x) ret+=tr[x],x-=lb(x);return ret;}//lalalala
int rnk[sz];//lalalala
signed main()
{
	file();//lalalala
	int i,x,y,z;//lalalala
	read>>n>>T;//lalalala
	for (i=1;i<=n;i++) read>>sum[i],sum[i]+=sum[i-1],a[i]=(hh){sum[i],i};
	a[n+1]=(hh){0,0};//lalalala
	sort(a+1,a+n+1+1,cmp);//lalalala
	for (i=1;i<=n+1;i++) rnk[a[i].id]=i;//lalalala
	ll ans=0;//lalalala
	add(x=rnk[0]+1);//lalalala
	for (i=1;i<=n;i++)
	{//lalalala
		ll x=sum[i]-T;
		y=upper_bound(a+1,a+n+1+1,(hh){x,0},cmp)-a;//I don't know what to write so I'm just typing random words lalalala
		ans+=query(n+1+1)-query(y);//I don't know what to write so I'm just typing random words lalalala
		z=rnk[i];//I don't know what to write so I'm just typing random words lalalala
		add(z+1);//I don't know what to write so I'm just typing random words lalalala
	}//I don't know what to write so I'm just typing random words lalalala
	cout<<ans;//I don't know what to write so I'm just typing random words lalalala
}