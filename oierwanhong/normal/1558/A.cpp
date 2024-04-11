#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
bool ok[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int a=read(),b=read();
		for(int i=0;i<=a+b;++i)ok[i]=0;
		if((a+b)&1)
		{
			int la=(a+b+1)/2,lb=(a+b)/2;
			//more A
			int match=min(a,la)+min(b,lb),up=min(b,la)+min(a,lb);
			for(int i=a+b-match;i<=up;i+=2)ok[i]=1;
			la=(a+b)/2,lb=(a+b+1)/2;
			match=min(a,la)+min(b,lb),up=min(b,la)+min(a,lb);
			for(int i=a+b-match;i<=up;i+=2)ok[i]=1;
		}
		else
		{
			int la=(a+b)/2,lb=(a+b)/2;
			int match=min(a,la)+min(b,lb),up=min(b,la)+min(a,lb);
			for(int i=a+b-match;i<=up;i+=2)ok[i]=1;
		}
		int cnt=0;
		for(int i=0;i<=a+b;++i)
			if(ok[i])++cnt;
		printf("%d\n",cnt);
		for(int i=0;i<=a+b;++i)
			if(ok[i])printf("%d ",i);
		puts("");
	}
	return 0;
}