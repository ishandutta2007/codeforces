#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,w,l,arr[maxn],pre[maxn],suf[maxn],h,r,q[maxn];
ll ans[maxn];
inline void add(int l,int r,ll v){if(l<=r) ans[l]+=v,ans[r+1]-=v;}//,printf("add(%d,%d,%lld)\n",l,r,v);}
int main(){
	n=read();w=read();
	FOR(i,1,n){
		l=read();
		FOR(j,1,l) arr[j]=read();
		if(l<=w/2){
			FOR(j,1,l){
				pre[j]=max(pre[j-1],arr[j]);
				add(j,j,pre[j]);
			}
			suf[l+1]=0;
			ROF(j,l,1){
				suf[j]=max(suf[j+1],arr[j]);
				add(j+w-l,j+w-l,suf[j]);
			}
			add(l+1,w-l,pre[l]);
		}
		else{
			FOR(j,1,w-l){
				pre[j]=max(pre[j-1],arr[j]);
				add(j,j,pre[j]);
			}
			suf[l+1]=0;
			ROF(j,l,l-(w-l)+1){
				suf[j]=max(suf[j+1],arr[j]);
				add(j+w-l,j+w-l,suf[j]);
			}
			h=1;r=0;
			FOR(j,1,l){
				while(h<=r && q[h]<j-(w-l)) h++;
				while(h<=r && arr[q[r]]<arr[j]) r--;
				q[++r]=j;
				if(j>=w-l+1) add(j,j,arr[q[h]]);
			}
		}
	}
	FOR(i,1,w) ans[i]+=ans[i-1];
	FOR(i,1,w) printf("%lld ",ans[i]);
}