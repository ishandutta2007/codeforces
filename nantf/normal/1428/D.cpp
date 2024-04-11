#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,upr,a[maxn],ans[maxn][2],al,cur1=1,cur2=1,cur3=1;
bool vis[maxn],vis2[maxn];
inline void add(int x,int y){
	ans[++al][0]=x;ans[al][1]=y;
}
int main(){
	upr=n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n){
		if(vis[i]) continue;
		vis[i]=true;
		while(cur1<=n && (a[cur1]!=1 || vis[cur1])) cur1++;
		while(cur2<=n && (a[cur2]!=2 || vis[cur2])) cur2++;
		while(cur3<=n && (a[cur3]!=3 || vis[cur3])) cur3++;
		if(a[i]==1){
			add(upr--,i);
		}
		else if(a[i]==2){
			if(cur1>n) return puts("-1"),0;
			vis[cur1]=true;
			add(upr,i);
			add(upr--,cur1);
		}
		else if(a[i]==3){
			if(cur1>n) return puts("-1"),0;
			if(cur1<cur2 && cur1<cur3){
				vis[cur1]=true;
				if(!vis2[i]) add(upr,i);
				add(upr--,cur1);
				add(upr--,cur1); 
			}
			else if(cur2<cur1 && cur2<cur3){
				vis[cur1]=vis[cur2]=true;
				if(!vis2[i]) add(upr,i);
				add(upr--,cur2);
				add(upr,cur2);
				add(upr--,cur1);
			}
			else{
				vis2[cur3]=true;
				if(!vis2[i]) add(upr,i);
				add(upr--,cur3);
				add(upr,cur3);
			}
		}
	}
	assert(upr>=0);
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d\n",n-ans[i][0]+1,ans[i][1]);
}