#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
namespace INPUT_SPACE{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
    inline int gc()
    {
        if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
        return (HD==TL)?EOF:*HD++;
    }
	inline int read()
    {
        int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
        while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
       /* int x;
        cin>>x;
        return x;*/
    }
}using INPUT_SPACE::read;
namespace OUTPUT_SPACE{
    char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
    inline int Flush() { return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0; }
}using OUTPUT_SPACE::print;using OUTPUT_SPACE::Flush;
#define id(x) ((x-1)/B+1)
const int N=1e5+55;
const int B=450;
int n,st,zs,b[N],m,op,x,y,cd[N];
struct Bruce{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)>>1)
	int zuo,you,id,siz[N*4],st[B+5],top;
	void add(int x,int v){
		x=cd[x];
		for(;x;x>>=1)siz[x]+=v;
	}
	int query(int u,int l,int r,int x){
		siz[u]--;
		if(l==r){
			st[++top]=l;
			return l;
		}
		if(siz[ls]>=x)return query(ls,l,mid,x);
		else return query(rs,mid+1,r,x-siz[ls]);
	}
	int ask(int u,int l,int r,int x){
		if(l==r){
			return l;
		}
		if(siz[ls]>=x)return ask(ls,l,mid,x);
		else return ask(rs,mid+1,r,x-siz[ls]);
	}
	void rebuild(int x){
		for(int i=zuo;i<=x;i++){
			add(st[top],1);
			top--;
		}
		for(int i=x;i>=zuo;i--)query(1,1,n,b[i]);
	}
	int tmp(int x){
		int ans=b[x];
		for(int i=x+1;i<=you;i++){
			if(b[i]<=ans)ans++;
		}
		return ans;
	}
}s[N/B+2];
void build(int u,int l,int r){
	if(l==r){
		cd[l]=u;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("cs.out","w",stdout);
	n=read();
	build(1,1,n);
//	cout<<zs;
	for(int i=1;i<=n;i++)b[i]=i-read();
	for(int i=1;i<=id(n);i++){
		s[i].id=i;
		s[i].zuo=(s[i-1].id*B+1);
		s[i].you=min(n,s[i].id*B);
		for(int k=1;k<=s[i].you;k++)s[i].add(k,1);
		for(int k=s[i].you;k>=s[i].zuo;k--){
			int hh=s[i].query(1,1,n,b[k]);
		}
	}
	m=read();
	for(int i=1;i<=m;i++){
		op=read();
		if(op==1){
			x=read();y=read();
			y=x-y;
			b[x]=y;
			s[id(x)].rebuild(x);
		}
		else{
			x=read();
			y=x;
			x=s[id(y)].tmp(y);
		//	cout<<"sese:"<<x<<endl;
			for(int k=id(y)+1;k<=id(n);k++){
		//		cout<<"yiw:"<<k<<" "<<x<<" "<<s[k].ask(1,1,n,x)<<endl;
				x=s[k].ask(1,1,n,x);
			}
			print(x);
		}
	}
	Flush();
	return 0;
}
/*
3
0 0 0
1
2 2
*/