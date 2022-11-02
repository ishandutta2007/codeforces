#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcountll(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int read(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
}using namespace IO_BUFF;
const int N=1e6+5;
const int M=60;
int n,a[N],s[N],ans,maxx[N],minn[N],hz[N],sa[M+5],sb[M+5];
#define mid ((l+r)>>1)
void solve(int l,int r){
	if(l==r){
		ans++;return ;
	}
	minn[mid+1]=maxx[mid+1]=a[mid+1];
	minn[mid]=maxx[mid]=a[mid];
	for(int i=mid+2;i<=r;i++){
		minn[i]=min(minn[i-1],a[i]);
		maxx[i]=max(maxx[i-1],a[i]);
	}
	for(int i=mid-1;i>=l;i--){
		maxx[i]=max(maxx[i+1],a[i]);
		minn[i]=min(minn[i+1],a[i]);
	}
	s[r+1]=0;
	for(int i=r;i>mid;i--){
		s[i]=s[i+1]+(bc(maxx[i])==bc(minn[i]));
	}
	vector<pii>q[r-mid+1],d[r-mid+1];
	for(int i=mid,head=mid,tail=mid;i>=l;i--){
		while(head<r && a[head+1]<=maxx[i])head++;
		while(tail<r && a[tail+1]>=minn[i])tail++;
		if(bc(maxx[i])==bc(minn[i]))ans=ans+min(head,tail)-mid; // all left >=
		ans=ans+s[max(head,tail)+1]; // all right >
		if(head!=tail){
			if(head<tail){
				int tmp=bc(minn[i]);
				d[head-mid].pb(mp(tmp,0));
				q[tail-mid].pb(mp(tmp,0));
			}
			else{
				int tmp=bc(maxx[i]);
				d[tail-mid].pb(mp(tmp,1));
				q[head-mid].pb(mp(tmp,1));
			}
		}
	}
	for(int i=mid+1;i<=r;i++){
		sa[bc(minn[i])]++;
		sb[bc(maxx[i])]++;
		for(auto k:q[i-mid]){
			if(k.se==0)ans=ans+sb[k.fi];
			else ans=ans+sa[k.fi];
		}
		for(auto k:d[i-mid]){
			if(k.se==0)ans=ans-sb[k.fi];
			else ans=ans-sa[k.fi];
		}
	}
	memset(sa,0,sizeof(sa));
	memset(sb,0,sizeof(sb));
	solve(l,mid);
	solve(mid+1,r);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	solve(1,n);
	cout<<ans;
	return 0;
}