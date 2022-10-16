#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,rmx,bmx,rcr,bcr,tp[maxn];
char str[maxn];
bool check(int x){
	rmx=bmx=rcr=bcr=0;
	FOR(i,1,n) if(str[i]=='('){
		if(rcr==x && bcr==x) return false;
		if(rcr==x) bcr++,tp[i]=1;
		else rcr++,tp[i]=0;
	}
	else{
		if(rcr>bcr) rcr--,tp[i]=0;
		else if(bcr) bcr--,tp[i]=1;
		else return false;
	}
	return true;
}
int main(){
	n=read();
	scanf("%s",str+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	check(r);
	FOR(i,1,n) printf("%d",tp[i]);
}