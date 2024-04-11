#include<bits/stdc++.h>
using namespace std;
int T,n,x,ans,f[233],tot;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&x);
		for(int i = 1; i <= n; i++) scanf("%d",&tot),f[tot]=1;
		tot=x;
		for(int i = 1; i <= 222; i++) {
			if(f[i]==0) tot--;
			if(tot==-1) {
				ans=i-1;
				break;
			}
		}
		for(int i = 1; i <= 222; i++) f[i]=0;
		printf("%d\n",ans);
	}
	return 0;
} 

/*
2
3
trump
ri
o
Donald John Trump (born June 14, 1946) is an American businessman, television personality, author, politician, and the Republican Party nominee for President of the United States in the 2016 election. He is chairman of The Trump Organization, which is the principal holding company for his real estate ventures and other business interests.
2
fuck
sb
Fuck you trump fuck you are sb.
*/
//#include<bits/stdc++.h>
//#define mod 10007
//using namespace std;
//int n,len,lens,sp[20009][26],dp[101][20009],fail[20009],u=0,v=1,use[20009],tot,now,ans,uuu=1;
//bool ts[20009];
//char a[20009];
//int head[20009],las[20009];
//struct node {
//	int val,nextt;
//} f[20009];
//void dfs(int x,bool flag) {
//	bool sflag=(flag|ts[now]);
//	ts[now]=sflag;
//	for(int i = head[x]; i != 0; i = f[i].nextt) dfs(i,sflag);
//}
//int main() {
//	scanf("%d%d",&n,&lens);
//	for(int i = 1; i <= n; i++) {
//		scanf("%s",&a);
//		len=strlen(a);
//		now=0;
//		for(int j = 0; j < len; j++) {
//			if(sp[now][a[j]-'A']==0) ++tot,sp[now][a[j]-'A']=tot;
//			now=sp[now][a[j]-'A'];
//		}
//		ts[now]=true;
//	}
//	while(u<v) {
//		++u;
//		for(int i = 0; i < 26; i++) {
//			if(sp[use[u]][i]==0) sp[use[u]][i]=sp[fail[use[u]]][i];
//			else fail[sp[use[u]][i]]=(use[u]==0?0:sp[fail[use[u]]][i]),++v,use[v]=sp[use[u]][i];
//		}
//	}
//	for(int i = 1; i <= tot; i++) {
//		if(head[fail[i]]==0) head[fail[i]]=i;
//		else f[las[fail[i]]].nextt=i;
//		las[fail[i]]=i;
//	}
//	dfs(0,false);
//	dp[0][0]=1;
//	for(int i = 1; i <= lens; i++)
//		for(int j = 0; j <= tot; j++)
//			for(int k = 0; k < 26; k++){
//				if(ts[sp[j][k]]==true) continue;
//				dp[i][sp[j][k]]=(dp[i][sp[j][k]]+dp[i-1][j])%mod;
//			}
//	for(int i = 0; i <= tot; i++) ans=(ans+dp[lens][i])%mod;
//	for(int i = 1; i <= lens; i++) uuu=uuu*26%mod;
//	printf("%d",(uuu-ans+mod)%mod) ;
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<queue>
//#define MOD (10007)
//#define  N  (10005)
//using namespace std;
//
//int Son[N][26],End[N],Fail[N];
//int n,m,sz,f[105][N],ans;
//char s[N];
//queue<int>q;
//
//void Insert(char s[])
//{
//    int now=0,len=strlen(s);
//    for (int i=0; i<len; ++i)
//    {
//        int x=s[i]-'A';
//        if (!Son[now][x]) Son[now][x]=++sz;
//        now=Son[now][x];
//    }
//    End[now]|=1;
//}
//
//void Build_Fail()
//{
//    for (int i=0; i<26; ++i)
//        if (Son[0][i])
//            q.push(Son[0][i]);
//    while (!q.empty())
//    {
//        int now=q.front();
//        q.pop();
//        for (int i=0; i<26; ++i)
//        {
//            if (!Son[now][i])
//            {
//                Son[now][i]=Son[Fail[now]][i];
//                continue;
//            }
//            End[Son[now][i]]|=End[Son[Fail[now]][i]];
//            Fail[Son[now][i]]=Son[Fail[now]][i];
//            q.push(Son[now][i]);
//        }
//
//    }
//}
//
//int main()
//{
//    scanf("%d%d",&n,&m);
//    for (int i=1; i<=n; ++i)
//        scanf("%s",s),Insert(s);
//    Build_Fail();
//    f[0][0]=1;
//    for (int i=1; i<=m; ++i)
//        for (int j=0; j<=sz; ++j)
//            for (int k=0; k<26; ++k)
//                if (!End[Son[j][k]])
//                    (f[i][Son[j][k]]+=f[i-1][j])%=MOD;
//    for (int i=0; i<=sz; ++i)
//        (ans+=f[m][i])%=MOD;
//    int sum=1;
//    for (int i=1; i<=m; ++i)
//        sum=sum*26%MOD;
//    printf("%d\n",(sum-ans+MOD)%MOD);
//}
//#include<bits/stdc++.h>
//using namespace std;
//int n,len,sp[1000009][26],fa[1000009],fail[1000009],u=0,v=1,use[1000009],ans[1000009],tot,now,sum[1000009];
//char a[1000009];
//int head[1000009],last[1000009];
//struct node {
//	int val,next;
//} f[1000009];
//int dfs(int x) {
//	for(int i = head[x]; i != 0; i = f[i].next) sum[x] += dfs(i);
//	return sum[x];
//}
//int main() {
//	scanf("%d",&n);
//	for(int i = 1; i <= n; i++) {
//		scanf("%s",&a);
//		len=strlen(a);
//		now=0;
//		for(int j = 0; j < len; j++) {
//			if(sp[now][a[j]-'a']==0) ++tot,sp[now][a[j]-'a']=tot,fa[tot]=now;
//			now=sp[now][a[j]-'a'];
//		}
//		ans[i]=now;
//	}
//	while(u<v) {
//		++u;
//		for(int i = 0; i < 26; i++) {
//			if(sp[use[u]][i]==0) sp[use[u]][i]=sp[fail[use[u]]][i];
//			else fail[sp[use[u]][i]]=(use[u]==0?0:sp[fail[use[u]]][i]),++v,use[v]=sp[use[u]][i];
//		}
//	}
//	scanf("%s",&a);
//	len=strlen(a);
//	now=0;
//	for(int i = 0; i < len; i++) now=sp[now][a[i]-'a'],sum[now]++;
//	for(int i = 1; i <= tot; i++) {
//		if(head[fail[i]]==0) head[fail[i]]=i;
//		else f[last[fail[i]]].next=i;
//		last[fail[i]]=i;
//	}
//	dfs(0);
//	now=0;
//	for(int i = 1; i <= n; i++) printf("%d\n",sum[ans[i]]);
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int m,n,opt,x;
//struct node{
//	int siz,son[2],val,rd;
//} p[1000009];
//int split(int k,int spx,int spy,int fx,int fy) {
//	if(spx==)
//}
//int main() {
//	scanf("%d",&m);
//	while(m--) {
//		scanf("%d%d",&opt,&x);
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//    scanf("%d%d",&n,&m);
//    for(int i = 1; i <= n; i++) f[i]=i;
//    for(int i = 1; i <= m; i++) scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].val);
//    sort(q+1,q+m+1,cmp);
//    for(int i = 1; i <= m; i++) {
//        if(find(q[i].u)==find(q[i].v)) continue;
//        f[find(q[i].u)]=find(q[i].v);
//        ans=max(ans,q[i].val);
//    }
//    printf("%d\n",ans);
//    return 0;
//}
//
//#include<bits/stdc++.h>
//#define mian main
//using namespace std;
//int a[1000009],k,tot,x,suma,sumb,sumc,sooke;
//int f[1000009],n,m,ans,fsum;
//struct node {
//    int val,u,v;
//} q[1000009];
//int find(int x){
//    return f[x]==x?x:find(f[x]);
//}
//bool cmp(node aa,node bb) {
//    return aa.val<bb.val;
//}
//int mian() {
//	srand((int)time(0));
//	scanf("%d%d",&n,&tot);
//    for(int i = 1; i <= n; i++) f[i]=i;
//    for(int i = 1; i <= m; i++) scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].val);
//	while(1) {
//		x=rand()%tot+1,sooke=q[x].val,suma=sumb=sumc=0;
//		for(int i = 1; i <= tot; i++) {
//			if(q[i].val< sooke) suma++;
//			if(q[i].val==sooke) sumb++;
//			if(q[i].val> sooke) sumc++;
//		}
//		if(suma<k&&suma+sumb>=k) {
//			printf("%d\n",a[x]);
//			return 0;
//		}
//		if(suma>=k) {
//			suma=0;
//			for(int i = 1; i <= tot; i++) if(q[i].val<sooke) ++suma,a[suma]=a[i];
//			tot=suma;
//			continue;
//		}
//		sumc=0;
//		for(int i = 1; i <= tot; i++) if(q[i].val>sooke) ++sumc,a[sumc]=a[i];
//		tot=sumc,k-=suma+sumb;
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int gen,ya[25][500001],x,y,n,m,deep[500001],p,Ta,Tb,zzz,B;
//int head[500001],last[500001];
//struct node {
//	int to,next;
//} q[1000001];
//void add_edge(int a,int b) {
//	++B,q[B].to=b;
//	if(head[a]==0) head[a]=B;
//	else q[last[a]].next=B;
//	last[a]=B;
//}
//inline int read() {
//	int s=0,w=1;
//	char ch=getchar();
//	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
//	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
//	return s*w;
//}
//int find(int a) {
//	if(deep[a]==0) return deep[a]=find(ya[0][a])+1;
//	else return deep[a];
//}
//void dfs(int aa) {
//	for(int i = head[aa]; i != 0; i = q[i].next)
//		if(q[i].to!=ya[0][aa])
//			ya[0][q[i].to]=aa,dfs(q[i].to);
//}
//int main() {
//	n=read(),m=read(),gen=read();
//	deep[gen]=1,ya[0][gen]=gen;
//	for(int i = 1; i < n; i++) {
//		x=read(),y=read();
//		add_edge(x,y);
//		add_edge(y,x);
//	}
//	dfs(gen);
//	for(int i = 1; i <= n; i++) {
//		if(deep[i]==0) find(i);
//	}
//	for(int i = 1; i <= log2(n); i++) {
//		for(int j = 1; j <= n; j++) {
//			ya[i][j]=ya[i-1][ya[i-1][j]];
//		}
//	}
//	for(int i = 1; i <= m; i++) {
//		x=read(),y=read();
//		if(deep[y]>deep[x]) swap(x,y);
//		p=deep[x]-deep[y],Ta=x,Tb=y,zzz=0;
//		while(p) {
//			if(p%2==1) Ta=ya[zzz][Ta];
//			p/=2;
//			++zzz;
//		}
//		for(int j = log2(n); j >= 0; j--) {
//			if(ya[j][Ta]!=ya[j][Tb]) {
//				Ta=ya[j][Ta],Tb=ya[j][Tb];
//			}
//		}
//		printf("%d\n",Ta==Tb?Ta:ya[0][Ta]);
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//#define mian main
//using namespace std;
//int T,n,m,k,a[3009][3009],s[3009],l[3009],tot;
//long long dp[3009],ans,qzh[3009][3009];
//int mian() {
//	scanf("%d",&T);
//	while(T--){
//		ans=0;
//		scanf("%d%d%d",&n,&m,&k);
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= m; j++)
//				scanf("%d",&a[i][j]),qzh[i][j]=qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1]+a[i][j];
//		for(int i = 1; i <= n; i++) {
//			tot=0;
//			for(int j = 1; j <= m; j++) {
//				if(a[i][j] >= k) l[j]++;
//				else l[j]=0;
//				while(tot!=0&&l[j]<=l[s[tot]]) --tot;
//				if(l[j]==0) dp[j]=0;
//				else dp[j]=dp[s[tot]]+qzh[i][j]+qzh[i-l[j]][s[tot]]-qzh[i][s[tot]]-qzh[i-l[j]][j];
//				ans=max(ans,dp[j]);
//				++tot,l[tot]=j;
//			}
//		}
//		printf("%lld\n",ans);
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int zhan[6001],dp[17001][2],n,m,cnt[15],K,maxn,ex,ey,p[16],KK,Froggyakioi;
//int f[16],ans,kh[6001][16];
//int a[106][106];
//void dfs(int aaa,int bbb,int ccc) {
//	if(ccc==m+2) {
//		++maxn;
//		zhan[maxn]=ans;
//		p[0]=0;
//		for(int i = 1; i <= (m+1); i++) {
//			if(f[i]==1) {
//				++p[0];
//				p[p[0]]=i;
//			}
//			if(f[i]==2) {
//				kh[maxn][i]=p[p[0]],kh[maxn][p[p[0]]]=i;
//				--p[0];
//			}
//		}
//		return;
//	}
//	if(m+1>=aaa+2*bbb+ccc) {
//		f[ccc]=0;
//		dfs(aaa,bbb,ccc+1);
//	}
//	if(bbb) {
//		ans+=cnt[ccc-1],f[ccc]=1;
//		dfs(aaa+1,bbb-1,ccc+1);
//		ans-=cnt[ccc-1];
//	}
//	if(aaa) {
//		ans+=2*cnt[ccc-1],f[ccc]=2;
//		dfs(aaa-1,bbb,ccc+1);
//		ans-=2*cnt[ccc-1];
//	}
//}
//int main() {
//	scanf("%d%d",&n,&m);
//	cnt[0]=1;
//	for(int i = 1; i <= (m+1); i++) cnt[i]=cnt[i-1]*3;
//	for(int i = 0; i <= (m+1)/2; i++)
//		dfs(0,i,1);
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)
//			cin>>a[i][j];
//	for(int k = 1; k <= maxn; k++) dp[zhan[k]][0]=dp[zhan[k]][1]=-1e8;
//	dp[0][0]=0;
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			if(n==i&&m==j) {
//				for(int k = 1; k <= maxn; k++) {
//					K=zhan[k];
//					int flaga=K/cnt[j-1]%3,flagb=K/cnt[j]%3;
//					if(flaga+flagb==0)
//						dp[K][1]=dp[K+cnt[j-1]+2*cnt[j]][0];
//				}
//				for(int k = 1; k <= maxn; k++) {
//					dp[zhan[k]][0]=dp[zhan[k]][1],dp[zhan[k]][1]=0;
//				}
//				continue;
//			}
//			for(int k = 1; k <= maxn; k++) {
//				K=zhan[k],Froggyakioi=dp[K][0]+a[i][j];
//				cout<<K<<endl;
//				int flaga=K/cnt[j-1]%3,flagb=K/cnt[j]%3,dsy=K-(flaga*cnt[j-1]+flagb*cnt[j]);
//				if(flaga==0&&flagb==0)
//					dp[K+cnt[j-1]+2*cnt[j]][1]=max(dp[K+cnt[j-1]+2*cnt[j]][1],Froggyakioi),dp[K][1]=max(dp[K][1],dp[K][0]);
//				else if(!flaga)
//					dp[dsy+flagb*cnt[j]][1]=max(dp[dp[dsy+flagb*cnt[j]][1]][1],Froggyakioi),dp[dsy+flagb*cnt[j-1]][1]=max(dp[dsy+flagb*cnt[j-1]][1],Froggyakioi);
//				else if(!flagb)
//					dp[dsy+flaga*cnt[j]][1]=max(dp[dsy+flaga*cnt[j]][1],Froggyakioi),dp[dsy+flaga*cnt[j-1]][1]=max(dp[dsy+flaga*cnt[j-1]][1],Froggyakioi);
//				else if(kh[k][j]!=j+1) {
//					int KK=dsy-(3-flaga)*cnt[kh[k][j]-1]-(3-flagb)*cnt[kh[k][j+1]-1];
//					if(kh[k][j+1]<kh[k][j])
//						dp[KK+cnt[kh[k][j+1]-1]+2*cnt[kh[k][j]-1]][1]=max(dp[KK+cnt[kh[k][j+1]-1]+2*cnt[kh[k][j]-1]][1],Froggyakioi);
//					else
//						dp[KK+2*cnt[kh[k][j+1]-1]+cnt[kh[k][j]-1]][1]=max(dp[KK+2*cnt[kh[k][j+1]-1]+cnt[kh[k][j]-1]][1],Froggyakioi);
//				}
//			}
//			if(j!=m) {
//				for(int k = 1; k <= maxn; k++) {
//					dp[zhan[k]][0]=dp[zhan[k]][1];
//					dp[zhan[k]][1]=-1e9;
//				}
//			} else {
//				for(int k = maxn; k >= 1; k--) {
//					K=zhan[k];
//					if(K%3==0) dp[K][0]=dp[K/3][1];
//					else dp[K][0]=-1e8;
//				}
//				for(int k = maxn; k >= 1; k--)
//					dp[zhan[k]][1]=-1e8;
//			}
//		}
//	}
//	printf("%d",dp[0][0]);
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,m,s[25],f[25],a[1<<24],val[1<<24];
//int main() {
//	scanf("%d",&n);
//	for(int i = 1; i <= n; i++) scanf("%d",&s[i]);
//	scanf("%d",&m);
//	for(int j = 1; j <= m; j++) scanf("%d",&f[i]);
//	for(int i = 0; i <= (1<<n)-1; i++) {
//		for(int j = 1; j <= n; j++) {
//			for(int k = 1; k <)
//		}
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,mod,m,s[100009],a[400009],lazya[400009],lazyb[400009],opt,l,r,spj;
//void dfs(int x,int uu,int vv)
//{
//    lazyb[x]=1;
//    if(uu==vv) a[x]=s[uu];
//    else {
//        dfs(x*2,uu,(uu+vv)/2);
//        dfs(x*2+1,(uu+vv)/2+1,vv);
//        a[x]=a[x*2]+a[x*2+1];
//    }
//}
//int que(int x,int uu,int vv,int ux,int vx)
//{
//    if(uu==ux&&vv==vx) return a[x];
//    int mid=(ux+vx)/2;
//    if(mid>=vv) return (que(x*2,uu,vv,ux,mid) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//    if(mid<uu) return (que(x*2+1,uu,vv,mid+1,vx) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//    return ((que(x*2,uu,mid,ux,mid) + que(x*2+1,mid+1,vv,mid+1,vx)) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//}
//void qa(int x,int uu,int vv,int ux,int vx,int pl)
//{
//    int mid=(ux+vx)/2;
//    if(uu==ux&&vv==vx) {lazya[x]=(lazya[x]+pl)%mod,a[x]=(a[x]+pl*(vx-ux+1))%mod;return;}
//    else if(mid>=vv) qa(x*2,uu,vv,ux,mid,pl);
//    else if(mid<uu) qa(x*2+1,uu,vv,mid+1,vx,pl);
//    else qa(x*2,uu,mid,ux,mid,pl),qa(x*2+1,mid+1,vv,mid+1,vx,pl);
//	a[x]=((a[x<<1]+a[x<<1|1])*lazyb[x]+lazya[x]*(vx-ux+1))%mod;
//}
//void qb(int x,int uu,int vv,int ux,int vx,int pl){
//    int mid=(ux+vx)/2;
//    if(uu==ux&&vv==vx) {lazyb[x]=lazyb[x]*pl%mod,lazya[x]=lazya[x]*pl%mod,a[x]=a[x]*pl%mod;return;}
//    else if(mid>=vv) qb(x*2,uu,vv,ux,mid,pl);
//    else if(mid<uu) qb(x*2+1,uu,vv,mid+1,vx,pl);
//    else qb(x*2,uu,mid,ux,mid,pl),qb(x*2+1,mid+1,vv,mid+1,vx,pl);
//	a[x]=((a[x<<1]+a[x<<1|1])*lazyb[x]+lazya[x]*(vx-ux+1))%mod;
//}
//signed main()
//{
//    scanf("%lld%lld%lld",&n,&m,&mod);
//    for(int i = 1; i <= n; i++) scanf("%lld",&s[i]);
//    dfs(1,1,n);
//    while(m--)
//    {
//        scanf("%lld%lld%lld",&opt,&l,&r);
//        if(opt==1) scanf("%lld",&spj),qb(1,l,r,1,n,spj);
//        if(opt==2) scanf("%lld",&spj),qa(1,l,r,1,n,spj);
//        if(opt==3) printf("%lld\n",que(1,l,r,1,n));
//        for(int i = 1; i <= n; i++) cout<<"sum="<<que(1,i,i,1,n)<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,mod,m,s[100009],a[400009],lazya[400009],lazyb[400009],opt,l,r,spj;
//void dfs(int x,int uu,int vv)
//{
//	lazyb[x]=1;
//	if(uu==vv) a[x]=s[uu];
//	else {
//		dfs(x*2,uu,(uu+vv)/2);
//		dfs(x*2+1,(uu+vv)/2+1,vv);
//		a[x]=a[x*2]+a[x*2+1];
//	}
//}
//int que(int x,int uu,int vv,int ux,int vx)
//{
//	if(uu==ux&&vv==vx) return a[x];
//	int mid=(ux+vx)/2;
//	if(mid>=vv) {
//		return (que(x*2,uu,vv,ux,mid) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//	}
//	if(mid<uu) {
//		return (que(x*2+1,uu,vv,mid+1,vx) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//	}
//	return ( (que(x*2,uu,mid,ux,mid) + que(x*2+1,mid+1,vv,mid+1,vx)) * lazyb[x] + lazya[x] * (vv-uu+1)) % mod;
//}
//int qa(int x,int uu,int vv,int ux,int vx,int pl)
//{
//	int ls=-a[x];
//	if(uu==ux&&vv==vx)
//	{
//		lazya[x]=(lazya[x]+pl)%mod;
//		a[x]=(a[x]+pl*(vv-uu+1))%mod;
//		return (ls+a[x]+mod)%mod;
//	}
//	int mid=(ux+vx)/2;
//	if(mid>=vv)
//	{
//		a[x]=(a[x]+qa(x*2,uu,vv,ux,mid,pl))%mod;
//		return (ls+a[x]+mod)%mod;
//	}
//	if(mid<uu)
//	{
//		a[x]=a[x]+qa(x*2+1,uu,vv,mid+1,vx,pl);
//		return (ls+a[x]+mod)%mod;
//	}
//	a[x]=(a[x]+qa(x*2,uu,mid,ux,mid,pl)+qa(x*2+1,mid+1,vv,mid+1,vx,pl))%mod;
//	return (ls+a[x]+mod)%mod;
//}
//int qb(int x,int uu,int vv,int ux,int vx,int pl){
//	int ls=-a[x];
//	if(uu==ux&&vv==vx)
//	{
//		lazyb[x]=lazyb[x]*pl%mod;
//		lazya[x]=lazya[x]*pl%mod;
//		a[x]=a[x]*pl%mod;
//		return (ls+a[x]+mod)%mod;
//	}
//	int mid=(ux+vx)/2;
//	if(mid>=vv)
//	{
//		a[x]=(a[x]+qb(x*2,uu,vv,ux,mid,pl))%mod;
//		return (ls+a[x]+mod)%mod;
//	}
//	if(mid<uu)
//	{
//		a[x]=a[x]+qb(x*2+1,uu,vv,mid+1,vx,pl);
//		return (ls+a[x]+mod)%mod;
//	}
//	a[x]=(a[x]+qb(x*2,uu,mid,ux,mid,pl)+qb(x*2+1,mid+1,vv,mid+1,vx,pl))%mod;
//	return (ls+a[x]+mod)%mod;
//}
//signed main()
//{
//	scanf("%lld%lld%lld",&n,&m,&mod);
//	for(int i = 1; i <= n; i++) scanf("%lld",&s[i]);
//	dfs(1,1,n);
//	while(m--)
//	{
//		scanf("%lld%lld%lld",&opt,&l,&r);
//		if(opt==1) scanf("%lld",&spj),qb(1,l,r,1,n,spj);
//		if(opt==2) scanf("%lld",&spj),qa(1,l,r,1,n,spj);
//		if(opt==3) printf("%lld\n",que(1,l,r,1,n));
//	}
//	return 0;
//}

//3 111111
//1 1 1
//4
//1 1 3 2
//2 1 3 1
//1 1 3 2
//3 1 2

//#include<iostream>
//#include<string.h>
//#include<stdio.h>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//long long mod;
//struct MM {
//    long long a[100][100];
//    long long N,M;
//    MM() {
//        memset(a,0,sizeof(a));
//    }
//    MM operator*(const MM &b) const {
//        MM res;
//        for (int i = 1; i <= N; i++)
//            for (int j = 1; j <= b.M; j++)
//                for (int k = 1; k <= M; k++)
//                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
//        res.N=N,res.M=b.M;
//        return res;
//    }
//} ans,q;
//MM ksm(MM aaa,long long bbb){
//    MM res,X=aaa;
//    long long TIME=bbb;
//    res.N=res.M=aaa.N;
//    for(int i = 1; i <= aaa.N; i++) res.a[i][i]=1;
//    while(TIME){
//        if(TIME%2) res=res*X;
//        X=X*X;
//        TIME/=2;
//    }
//    return res;
//}
//long long P,Q,aa,bb,k;
//int main() {
//    scanf("%lld%lld%lld%lld%lld%lld",&P,&Q,&aa,&bb,&k,&mod);
//    q.N=q.M=ans.M=2,ans.N=1;
//    q.a[1][1]=P,q.a[1][2]=1;
//    q.a[2][1]=Q,q.a[2][2]=0;
//    ans.a[1][1]=bb,ans.a[1][2]=aa,ans;
//    ans=ans*ksm(q,k-1);
//    printf("%lld\n",ans.a[1][2]);
//    return 0;
//}

//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//struct node {
//	int x,y,z;
//} a[2000001];
//bool cmp(node s,node b) {return s.z<b.z;}
//int b[100001],f[100001],n,m,kkk,ans,dina,dinb;
//int find(int x) {
//	if(x==f[x]) return x;
//	else return f[x]=find(f[x]);
//}
//signed main() {
//	scanf("%lld",&n);
//	for(int i = 1; i <= n; i++) f[i]=i;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= n; j++)
//			++m,a[m].x=i,a[m].y=j,scanf("%lld",&a[m].z);
//	sort(a+1,a+m+1,cmp);
//	scanf("%lld",&kkk);
//	while(kkk--) scanf("%d%d",&dina,&dinb),f[find(dina)]=find(dinb);
//	for(int i = 1; i <= m; i++) if(find(a[i].x)!=find(a[i].y)) f[find(a[i].x)]=find(a[i].y),ans+=a[i].z;
//	int flag=0;
//	for(int i = 1; i <= n; i++) if(find(i)!=find(1))flag=1;
//	printf("%lld",ans);
//	return 0;
//}

//#include<iostream>
//#include<string.h>
//#include<cstdio>
//#include<algorithm>
//#include<vector>
//#include<map>
//using namespace std;
//int n,m,head[100009],last[100009],qwq[200009],tot,ans;
//struct node{
//	int val,next;
//} e[100009];
//int main() {
//	scanf("%d%d",&m,&n);
//	for(int i = 1; i <= n; i++) {
//		scanf("%d",&e[i].val);
//		if(head[e[i].val]==0) head[e[i].val]=i;
//		else e[last[e[i].val]].next=i;
//		last[e[i].val]=i;
//	}
//	for(int color = 1; color <= m; color++) {
//		if(head[color]==0) continue;
//		tot=0;
//		for(int i = head[color]; i != 0; i = e[i].next) {
//			if(i!=1) if(e[i-1].val!=i) ++tot,qwq[tot]=e[i-1].val;
//			if(i!=n) if(e[i+1].val!=i) ++tot,qwq[tot]=e[i+1].val;
//		}
//		sort(qwq+1,qwq+n+1);
//		for(int i = 1; i )
//	}
//	return 0;
//}