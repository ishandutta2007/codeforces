#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
	int x,w;
}P[200010];
int c[400010],f[200010],data[200010],need[200010],b[400010],n,x,w,ans;
char ch;
bool cmp(point a,point b){return a.x<b.x;}
void getint(int &x)
{
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
inline int lowbit(int x){return x&(-x);}
void add(int x,int y){for(;x<=2*n;x+=lowbit(x))c[x]=max(c[x],y);}
int query(int x){int s=0;for(;x;x-=lowbit(x))s=max(s,c[x]);return s;}
int main()
{
	getint(n);for(int i=1;i<=n;i++){getint(P[i].x);getint(P[i].w);}
	sort(P+1,P+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		x=P[i].x;w=P[i].w;
		b[2*i-1]=data[i]=x+w;
		b[2*i]=need[i]=x-w;
	}
	sort(b+1,b+2*n+1);
	for(int i=1;i<=n;i++)
	{
		data[i]=lower_bound(b+1,b+2*n+1,data[i])-b;
		need[i]=lower_bound(b+1,b+2*n+1,need[i])-b;
	}
	add(data[1],ans=f[1]=1);
	for(int i=2;i<=n;i++){f[i]=query(need[i])+1;ans=max(ans,f[i]);add(data[i],f[i]);}
	printf("%d",ans);
	return 0;
}