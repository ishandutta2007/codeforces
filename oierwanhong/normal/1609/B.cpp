#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
char a[2000011];
bool check(int x){return x>1&&a[x-1]=='a'&&a[x]=='b'&&a[x+1]=='c';}
int main()
{
	int n=read(),q=read();
	scanf("%s",a+1);
	int cnt=0;
	for(int i=2;i<=n;++i) cnt+= check(i);
	while(q--)
	{
		int i=read();
		char ch=getchar();
		while(ch!='a'&&ch!='b'&&ch!='c')ch=getchar();
		cnt-=check(i-1)+check(i)+check(i+1);
		a[i]=ch;
		cnt+=check(i-1)+check(i)+check(i+1);
		printf("%d\n",cnt);
	}
	return 0;
}