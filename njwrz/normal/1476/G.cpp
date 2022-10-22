/*

DP





ll int
 dp 










*/
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int B;
int n,m;
int a[100005],bl[100005],tim[100005],b[100005],ans[100005];
int l[100005],p[100005],r[100005],k[100005],cnt1,cnt2,cnt[100005],cntnode;
P<int,int> c[100005],node[15000005];
V<int> recycle;
bool cmp(int x,int y){
	RE MP(MP(bl[l[x]],bl[r[x]]),tim[x])<MP(MP(bl[l[y]],bl[r[y]]),tim[y]);
}
int lst[15000005],nxt[15000005],address[100005];
int START=1,END=2;
int ccnt,cntn;
P<int,int> cc[100005];
void in(int x){
	if(recycle.empty()){
		address[x]=++cntnode;
	}else{
		address[x]=recycle.back();
		recycle.pop_back();
	}
	node[address[x]]=MP(x,0);
	lst[address[x]]=START;
	nxt[address[x]]=nxt[START];
	lst[nxt[START]]=address[x];
	nxt[START]=address[x];
}
void out(int x){
	lst[nxt[address[x]]]=lst[address[x]];
	nxt[lst[address[x]]]=nxt[address[x]];
	recycle.PB(address[x]);
	address[x]=-1;
}
void add2(int x){
	if(address[x]==-1){
		in(x);
	}
	node[address[x]].S++;
}
void del2(int x){
	node[address[x]].S--;
	if(!node[address[x]].S){
		out(x);
	} 
}
void add(int x){
	if(cnt[x])del2(cnt[x]);
	cnt[x]++;
	add2(cnt[x]);
}
void del(int x){
	del2(cnt[x]);
	cnt[x]--;
	if(cnt[x])add2(cnt[x]);
}
signed main(){
	FILL(address,-1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	nxt[1]=2;
	lst[2]=1;
	cin>>n>>m; 
	B=pow(n,0.666666);
	FOR(i,1,n)cin>>a[i],bl[i]=(i-1)/B+1,b[i]=a[i];
	FOR(i,1,m){
		ans[i]=1e9;
		int tag;
		cin>>tag;
		if(tag==1){
			cnt1++;
			cin>>l[i]>>r[i]>>k[i];
			tim[i]=cnt2;
			p[cnt1]=i;
		}else{
			cnt2++;
			cin>>c[cnt2].F>>c[cnt2].S;
		}
	}
	cntnode=2;
	FOR(i,1,n)a[i]=b[i];
	sort(p+1,p+cnt1+1,cmp);
	int tl=1,tr=0,ttim=0;
	V<P<int,int> > anv;
	FOR(_,1,cnt1){
		int now=p[_],iter,sum;
		while(tl>l[now])add(a[--tl]);
		while(tr<r[now])add(a[++tr]);
		while(tl<l[now])del(a[tl++]);
		while(tr>r[now])del(a[tr--]);
		while(ttim<tim[now]){
			ttim++;
			if(c[ttim].F>=l[now]&&c[ttim].F<=r[now])del(a[c[ttim].F]);
			swap(a[c[ttim].F],c[ttim].S);
			if(c[ttim].F>=l[now]&&c[ttim].F<=r[now])add(a[c[ttim].F]);
		}
		while(ttim>tim[now]){
			if(c[ttim].F>=l[now]&&c[ttim].F<=r[now])del(a[c[ttim].F]);
			swap(a[c[ttim].F],c[ttim].S);
			if(c[ttim].F>=l[now]&&c[ttim].F<=r[now])add(a[c[ttim].F]);
			ttim--;
		}
		iter=START,sum=0;
		ccnt=0;
		while(nxt[iter]!=END){
			iter=nxt[iter];
			cc[++ccnt]=node[iter];
			sum+=node[iter].S;
		}
		sort(cc+1,cc+ccnt+1);
		if(sum<k[now]){
			ans[now]=-1;
			anv.PB(MP(now,ans[now]));continue;
		}
		int lft=1,nows=0;
		FOR(i,1,ccnt){
			nows+=cc[i].S;
			if(nows>=k[now]){
				while(nows-cc[lft].S>=k[now]){
					nows-=cc[lft].S;
					lft++;
				}
				gmin(ans[now],cc[i].F-cc[lft].F);
			}
		}
		anv.PB(MP(now,ans[now]));
	}
	sort(ALL(anv));
	for(auto u:anv){
		cout<<u.S<<'\n';
	}
	RE 0;
}