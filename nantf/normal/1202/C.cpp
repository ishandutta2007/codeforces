#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
#define MP make_pair
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
int t,n,n1,n2,pre1[maxn],suf1[maxn],pre2[maxn],suf2[maxn];
int mnpre1[maxn],mxpre1[maxn],mnpre2[maxn],mxpre2[maxn],mnsuf1[maxn],mxsuf1[maxn],mnsuf2[maxn],mxsuf2[maxn];
int s1[maxn],s2[maxn];
ll ans;
char s[maxn];
void calc(int n,int a[],int pre[],int suf[],int mnpre[],int mxpre[],int mnsuf[],int mxsuf[]){
	FOR(i,1,n) pre[i]=pre[i-1]+a[i];
	ROF(i,n,1) suf[i]=suf[i+1]+a[i];
	FOR(i,1,n) mnpre[i]=a[i]+min(0,mnpre[i-1]),mxpre[i]=a[i]+max(0,mxpre[i-1]);
	ROF(i,n,1) mnsuf[i]=min(mnsuf[i+1],suf[i]),mxsuf[i]=max(mxsuf[i+1],suf[i]);
//	FOR(i,1,n) printf("pre[%d]=%d,suf[%d]=%d,mnpre[%d]=%d,mxpre[%d]=%d,mnsuf[%d]=%d,mxsuf[%d]=%d\n",i,pre[i],i,suf[i],i,mnpre[i],i,mxpre[i],i,mnsuf[i],i,mxsuf[i]);
}
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		n1=n2=0;
		FOR(i,1,n){
			if(s[i]=='W') s1[++n1]=1;
			else if(s[i]=='S') s1[++n1]=-1;
			else if(s[i]=='A') s2[++n2]=1;
			else s2[++n2]=-1;
		}
		calc(n1,s1,pre1,suf1,mnpre1,mxpre1,mnsuf1,mxsuf1);
		calc(n2,s2,pre2,suf2,mnpre2,mxpre2,mnsuf2,mxsuf2);
		ans=1ll*(mxsuf2[1]-mnsuf2[1]+1)*(mxsuf1[1]-mnsuf1[1]+1);
//		cout<<ans<<endl;
		FOR(i,0,n1) ans=min(ans,1ll*(mxsuf2[1]-mnsuf2[1]+1)*(
		min(
		max(mxsuf1[i+1],suf1[i+1]+1+max(mxpre1[i],0))-min(mnsuf1[i+1],suf1[i+1]+1+min(mnpre1[i],0)),
		max(mxsuf1[i+1],suf1[i+1]-1+max(mxpre1[i],0))-min(mnsuf1[i+1],suf1[i+1]-1+min(mnpre1[i],0))
		)+1));
//		cout<<ans<<endl;
		FOR(i,0,n2) ans=min(ans,1ll*(mxsuf1[1]-mnsuf1[1]+1)*(
		min(
		max(mxsuf2[i+1],suf2[i+1]+1+max(mxpre2[i],0))-min(mnsuf2[i+1],suf2[i+1]+1+min(mnpre2[i],0)),
		max(mxsuf2[i+1],suf2[i+1]-1+max(mxpre2[i],0))-min(mnsuf2[i+1],suf2[i+1]-1+min(mnpre2[i],0))
		)+1));
		cout<<ans<<endl;
		FOR(i,0,n+1) pre1[i]=suf1[i]=pre2[i]=suf2[i]=mxpre1[i]=mnpre1[i]=mxsuf1[i]=mnsuf1[i]=mxpre2[i]=mnpre2[i]=mxsuf2[i]=mnsuf2[i]=0;
	}
}