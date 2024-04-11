
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	 ll x=0;bool f=0;char c=getchar();
	 while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	 while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	 return f?-x:x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 5011;
int a[MAXN],ori[MAXN];
bool used[MAXN];
pii loc[5000011];
int find(int x)
{
	int i=1;
	while(ori[i]!=x||used[i])++i;
	return i;
}
int main()
{
	 int n=min(read(),5000);
	 for(int i=1;i<=n;++i)a[i]=ori[i]=read();
	 std::sort(a+1,a+n+1);
	 for(int i=n;i;--i)
	 {
		 for(int j=1;j<i;++j)
			 if(loc[a[i]-a[j]].first)
			 {
				 puts("YES");
				 int p=find(a[j]);
				 printf("%d ",p),used[p]=1;
				 p=find(loc[a[i]-a[j]].second),printf("%d ",p),used[p]=1;
				 p=find(a[i]),printf("%d ",p),used[p]=1;
				 p=find(loc[a[i]-a[j]].first),printf("%d ",p),used[p]=1;
				 return 0;
			 }
		 for(int j=i+1;j<=n;++j)
			 if(!loc[a[j]-a[i]].first)loc[a[j]-a[i]]=pii(a[i],a[j]);
	 }
	 puts("NO");
	 return 0;
}