#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct segment{
	int l,r,id;
	bool operator<(const segment &s)const{
		if(l!=s.l) return l<s.l;
		return r<s.r;
	}
}seg[100010];
int t,n,ans[100010];
int main(){
	t=read();
	while(t--){
		n=read();
		FOR(i,1,n) seg[i].l=read(),seg[i].r=read(),seg[i].id=i;
		sort(seg+1,seg+n+1);
		bool flag=false;
		ans[seg[1].id]=1;int pre=1,maxr=seg[1].r;
		FOR(i,2,n){
			if(seg[i].l>maxr){
				maxr=seg[i].r;
				ans[seg[i].id]=3-ans[seg[pre].id];
				if(ans[seg[i].id]==2) flag=true;
				pre=i;
				continue;
			}
			maxr=max(maxr,seg[i].r);
			ans[seg[i].id]=ans[seg[pre].id];
			if(ans[seg[i].id]==2) flag=true;
		}
		if(!flag) puts("-1");
		else{
			FOR(i,1,n) printf("%d ",ans[i]);puts("");
		}
	}
}