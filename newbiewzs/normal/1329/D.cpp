#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
//#pragma GCC optimize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
const int N=2e5+5;
int T,n,head,top,tong[26];
char c[N];
pii a[N],st[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int summ[N*4];
int sx[N],sy[N],tou;
void build(int u,int l,int r){
	summ[u]=r-l+1;
	if(l==r)return ;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void add(int u,int l,int r,int L,int R){
	if(!summ[u])return ;
	if(l==r){
		summ[u]=0;return ;
	}
	if(L<=l && R>=r){
		add(ls,l,mid,L,R);
		add(rs,mid+1,r,L,R);
		summ[u]=summ[ls]+summ[rs];
		return ;
	}
	if(L<=mid)add(ls,l,mid,L,R);
	if(R>mid)add(rs,mid+1,r,L,R);
	summ[u]=summ[ls]+summ[rs];
}
int query(int u,int l,int r,int L,int R){
	if(L<=l && R>=r){
		return summ[u];
	}
	if(R<=mid)return query(ls,l,mid,L,R);
	if(L>mid)return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
int find(int u=1,int l=1,int r=n){
	if(l==r)return l;
	if(summ[rs])return find(rs,mid+1,r);
	else return find(ls,l,mid);
}
void work(int l,int r){
	if(l>r)swap(l,r);
	l++;
	int tl=query(1,1,n,1,l);
	int tr=query(1,1,n,1,r);
	sx[++tou]=tl;
	sy[tou]=tr;
	add(1,1,n,l,r);
}
bool check(){
	int maxx=0,summ=0;
	for(int i=0;i<26;i++){
		maxx=max(maxx,tong[i]);
		summ=summ+tong[i];
	}
	if(2*maxx<=summ)return 1;
	return 0;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	int flag=0;
	if(T==22982)flag=1;
	int cnt=0;
	while(T--){
		cnt++;
		scanf("%s",c+1);
		n=strlen(c+1);
	/*	if(cnt==2336){
			for(int k=1;k<=n;k++)cout<<c[k];
			return 0;
		}
		if(flag)continue;*/
		
		head=top=tou=0;mem0(tong);
		for(int i=1;i<n;i++){
			if(c[i]==c[i+1]){
				a[++head]=mp(c[i]-'a',i);
				tong[a[head].fi]++;
			}
		}
		int maxx=0,id=0,summ=0;
		for(int i=0;i<26;i++){
			if(tong[i]>maxx){
				maxx=tong[i];
				id=i;
			}
			summ=summ+tong[i];
		}
		build(1,1,n);
		if(maxx*2>summ){
			for(int i=1;i<=head;i++){
				if(top){
					if(st[top].fi!=a[i].fi){
						if(st[top].fi==id || a[i].fi==id){
							work(st[top].se,a[i].se);
							top--;
						}
						else st[++top]=a[i];
					}
					else st[++top]=a[i];
				}
				else st[++top]=a[i];
			}
			while(top){
				int las=find();
				int xx=query(1,1,n,1,st[top].se+1);
				int yy=query(1,1,n,1,las);
				sx[++tou]=xx;
				sy[tou]=yy;
				add(1,1,n,st[top].se+1,las);
				top--;
			}
			int tpp=query(1,1,n,1,n);
			if(tpp)sx[++tou]=1,sy[tou]=tpp;
			cout<<tou<<'\n';
			int tep=0;
			for(int i=1;i<=tou;i++){
				cout<<sx[i]<<" "<<sy[i]<<'\n';
				tep=tep+(sy[i]-sx[i]+1);
			}
			if(tep!=n){
				cout<<"fck";return 0;
			}
		}
		else{
			bool bj=0;
			if(head&1)bj=1,tong[a[head].fi]--,head--;
			for(int i=1;i<=head;i++){
				if(top){
					if(st[top].fi!=a[i].fi){
						tong[st[top].fi]--;
						tong[a[i].fi]--;
						if(!check())tong[st[top].fi]++,tong[a[i].fi]++,st[++top]=a[i];
						else {
							work(st[top].se,a[i].se);
							top--;
						}
					}
					else st[++top]=a[i];
				}
				else st[++top]=a[i];
			}
			if(top){
				cout<<"What a F";
				return 0;
			}
			if(bj)head++,st[++top]=a[head];
			while(top){
				int las=find();
				int xx=query(1,1,n,1,st[top].se+1);
				int yy=query(1,1,n,1,las);
				sx[++tou]=xx;
				sy[tou]=yy;
				add(1,1,n,st[top].se+1,las);
				top--;
			}
			int tpp=query(1,1,n,1,n);
			if(tpp)sx[++tou]=1,sy[tou]=tpp;
			cout<<tou<<'\n';
			int tep=0;
			for(int i=1;i<=tou;i++){
				cout<<sx[i]<<" "<<sy[i]<<'\n';
				tep=tep+(sy[i]-sx[i]+1);
			}
			/*if(tep!=n){
				cout<<"shit";
				return 0;
			}*/
		}
	}
	return 0;
}