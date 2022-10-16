#include<bits/stdc++.h>
using namespace std;
const int maxn=300030;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,a[maxn];
bool check(int x){
	int mx=0;
	FOR(i,1,n){
		int l=a[i],r=(a[i]+x)%m;
		if(l<=r){
			if(r<mx) return false;
			mx=max(mx,max(l,mx));
		}
		else{
			if(r<mx) mx=max(mx,l);
		}
	}
	return true;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	int l=0,r=m-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}