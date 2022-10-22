// Problem: J. Bob's Beautiful Array
// Contest: Codeforces - Bubble Cup 14 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred, Div. 1)
// URL: https://codeforces.com/contest/1599/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#include <time.h>
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[1005],p[1000006],c[1000005],d[1005];
signed main()
{
	srand(time(0));
	int n=read();
	rg(n)a[i]=read();gr
	if(n==2){if(a[1]==a[2]){puts("YES");odp(a[1],0);}else{puts("NO");}return 0;}
	std::sort(a+1,a+1+n,[&](int x,int y){return (x&1)<(y&1);});
	if(a[3]&1)
	{
		if(a[2]&1)
		{
			if(a[1]&1)
			{
				rg(n)c[a[i]]++;gr
				if(0)
				{
				rg(n)rg_(j,n)if(i!=j&&a[i]>=a[j])p[a[i]-a[j]]++;gr gr
					puts("YES");
					int f=0,g=0;
					rg(n)if(c[a[i]]>=2&&f==0)d[i]=1,g=i,f=1;
					else if(a[i]==a[g]&&f==1)f=2,d[i]=1;gr
					odb(a[g]),odb(0);
					rg(n)if(!d[i])odb(a[i]);gr
				}
				else
				{
					clock_t AA=clock();
					rg(10000000)std::random_shuffle(a+1,a+1+n);
					rg(n)d[i]=d[i-1]+a[i];gr
					rg(n>>1)std::unordered_map<int,int>mp;
					rg_(j,n)if(j<i)continue;
					int s=d[j]-d[j-i];
					if(mp[s])
					{
						puts("YES");
//						printf("find lth = %d\n %d %d\n",i,mp[s],j);
//						rg(n)odb(a[i]);gr puts("");
						int k=0;	
						rg_(g,i)odb(k),k=a[mp[s]+1-g]-k;
						odb(k);k=a[j+1-g]-k;p[mp[s]+1-g]=p[j+1-g]=1;gr
						rg(n)if(p[i]==0)odb(a[i]);gr
						return 0;
					}
					else mp[s]=j;
					gr
					gr
					if((double)(clock()-AA)/CLOCKS_PER_SEC>0.9)break;
					gr
					puts("NO");
				}
			}
			else
			{
				int A=a[1],B=a[2],C=a[3],D=A+B+C>>1;
				puts("YES");
				odb(D-A),odb(D-B),odb(D-C);D-=A;
				rg(n)if(i>3)odb(a[i]-D);gr
			}
		}
		else
		{
			if(n==3)
			{
				if(a[1]==a[2])
				{
					puts("YES");
					printf("%d %d %d\n",a[1],0,a[3]-a[1]);
				}
				else puts("NO");
			}
			else
			{
				a[1]^=a[4]^=a[1]^=a[4];
				int A=a[1],B=a[2],C=a[3],D=A+B+C>>1;
				puts("YES");
				odb(D-A),odb(D-B),odb(D-C);D-=A;
				rg(n)if(i>3)odb(a[i]-D);gr
			}
		}
	}
	else
	{
		int A=a[1],B=a[2],C=a[3],D=A+B+C>>1;
		puts("YES");
		odb(D-A),odb(D-B),odb(D-C);D-=A;
		rg(n)if(i>3)odb(a[i]-D);gr
	}
	//int A0=
	//a+b=A
	//b+c=B
	//c+a=C
	//(A+B+C)/2
	return 0;
}