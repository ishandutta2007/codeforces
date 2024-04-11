#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/

const int MAXN = 200011;
char s[MAXN],t[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int pos=n,fail=0;
		for(int i=m;i;--i)
		{
			while(pos>=1&&t[i]!=s[pos])pos-=2;
			if(pos<1||t[i]!=s[pos]){fail=1;break;}
			--pos;
		}
		puts(fail?"NO":"YES");
	}
	return 0;
}