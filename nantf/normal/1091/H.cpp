#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,f,a[maxn],mx,sg[maxn],pr[maxn],pl,s;
bitset<maxn> b[111],tr;
bool vis[maxn];
int main(){
	n=read();f=read();
	FOR(i,1,n){
		int x=read(),y=read(),z=read();
		mx=max(mx,a[2*i-1]=y-x);
		mx=max(mx,a[2*i]=z-y);
	}
	n*=2;
	FOR(i,2,mx){
		if(!vis[i]) tr[i]=1,pr[++pl]=i;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>mx) break;
			vis[k]=true;
			if(!vis[i]) tr[k]=true;
			if(i%pr[j]==0) break;
		}
	}
	tr[f]=0;
	FOR(i,1,mx){
		FOR(j,0,mx) if(!b[j][i]){sg[i]=j;break;}
		b[sg[i]]|=tr<<i;
	}
	FOR(i,1,n) s^=sg[a[i]];
	if(s) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
}