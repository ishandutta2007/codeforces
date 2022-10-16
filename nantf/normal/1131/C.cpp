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
int n,a[111],b[111],ans=INT_MAX,aaa[111];
bool vis[111];
bool check(int x){
	int m=1,lst=1;
	b[1]=a[1];
	MEM(vis,0);
	FOR(i,2,n){
		if(a[i]-a[lst]>x){
			if(i==lst+1) return false;
			b[++m]=a[--i];
			lst=i;
			vis[i]=true;
		}
	}
	ROF(i,n,2) if(!vis[i]) b[++m]=a[i];
	FOR(i,1,n-1) if(abs(b[i]-b[i+1])>x) return false;
	if(abs(b[1]-b[n])>x) return false;
	FOR(i,1,n) aaa[i]=b[i];
	return true;
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	FOR(i,1,n) printf("%d ",aaa[i]);
}