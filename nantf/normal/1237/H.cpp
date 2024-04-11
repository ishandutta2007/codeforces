#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=4444,mod=998244353;
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
char s[maxn],t[maxn];
int n,scnt[4],tcnt[4],ans[maxn],al;
void work(int x){
	if(!x) return;
	ans[++al]=x;
	reverse(s+1,s+x+1);
}
inline int tr(char *s,int i){
	return 2*(s[2*i-1]-'0')+s[2*i]-'0';
}
inline int rtr(char *s,int i){
	return 2*(s[2*i]-'0')+s[2*i-1]-'0';
}
void solve(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	MEM(scnt,0);MEM(tcnt,0);
	FOR(i,1,n/2){
		scnt[tr(s,i)]++;
		tcnt[tr(t,i)]++;
	}
	if(scnt[0]!=tcnt[0] || scnt[1]+scnt[2]!=tcnt[1]+tcnt[2] || scnt[3]!=tcnt[3]) puts("-1");
	else{
		al=0;
		int flag=0;
		int s1=scnt[1],s2=scnt[2];
		FOR(i,1,n/2){
			scnt[tr(s,i)]--;
			scnt[rtr(s,i)]++;
			if(scnt[1]==tcnt[2]){flag=-1;work(2*i);break;}
		}
		if(!flag){
			scnt[1]=s1;scnt[2]=s2;
			FOR(i,1,n/2){
				tcnt[tr(t,i)]--;
				tcnt[rtr(t,i)]++;
				if(scnt[1]==tcnt[2]){flag=2*i;reverse(t+1,t+2*i+1);break;}
			}
		}
		FOR(i,1,n/2){
			FOR(j,i,n/2) if(tr(t,n/2-i+1)==rtr(s,j)){work(2*j-2),work(2*j);break;}
		}
		if(flag>0) ans[++al]=flag;
		printf("%d\n",al);
		FOR(i,1,al) printf("%d ",ans[i]);
		puts("");
	}
}
int main(){
	int T=read();
	while(T--) solve();
}