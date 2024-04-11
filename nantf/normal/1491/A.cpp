#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define PB push_back
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
int n,q,a[maxn],cnt[2];
int main(){
	n=read();q=read();
	FOR(i,1,n) cnt[a[i]=read()]++;
	while(q--){
		int op=read(),x=read();
		if(op==1){
			cnt[a[x]]--;
			a[x]^=1;
			cnt[a[x]]++;
		}
		else{
			if(cnt[1]>=x) puts("1");
			else puts("0");
		}
	}
}