#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
const int INF=0x3f3f3f3f;

char str[10001];
int n,ans;
int cnt[26];

int h[26],siz[26],nxt[10001],to[10001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%s",str);
	n=strlen(str);
	F2(i,0,n) ins(str[i]-'a',i), ++siz[str[i]-'a'];
	F2(i,0,26){
		int sums=0;
		F2(k,0,n){
			int sum=0;
			memset(cnt,0,sizeof cnt);
			eF(j,i)
				++cnt[str[(to[j]+k)%n]-'a'];
			F2(j,0,26) if(cnt[j]==1) ++sum;
			sums=max(sums,sum);
		}
		ans+=sums;
	}
	printf("%f",(ld)ans/n);
	return 0;
}