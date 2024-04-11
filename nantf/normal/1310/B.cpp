#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
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
int n,k,f[maxn][2][2],ans;
bool isf[maxn];
inline void chkmax(int &x,int y){x=max(x,y);}
void DP(int o,int l,int r){
	if(l+1==r){
		f[o][isf[l]][isf[r]]=f[o][isf[r]][isf[l]]=isf[l]|isf[r];
		return;
	}
	int mid=(l+r)>>1;
	DP(lson);DP(rson);
	FOR(w,0,1) FOR(x,0,1) FOR(y,0,1) FOR(z,0,1) FOR(a,0,1) FOR(b,0,1) FOR(c,0,1){
		int winup=a?w:y,loseup=a?y:w;
		int windn=b?x:z,losedn=b?z:x;
		int winre=c?loseup:windn,losere=c?windn:loseup;
		chkmax(f[o][winup][winre],f[o<<1][w][x]+f[o<<1|1][y][z]+(winup|loseup)+(windn|losedn)+(winre|losere));
	}
} 
int main(){
	n=read();k=read();
	while(k--) isf[read()]=true;
	MEM(f,~0x3f); 
	DP(1,1,1<<n);
	FOR(i,0,1) FOR(j,0,1) chkmax(ans,f[1][i][j]+(i|j));
	printf("%d\n",ans);
}
// fk