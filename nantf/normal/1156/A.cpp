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
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],ans;
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,2,n){
		if(a[i]==1){
			if(a[i-1]==2) ans+=3;
			if(a[i-1]==3) ans+=4;
		}
		else if(a[i]==2){
			if(a[i-1]==1){
				ans+=3;
				if(a[i-2]==3) ans--;
			}
			if(a[i-1]==3) return puts("Infinite"),0;
		}
		else if(a[i]==3){
			if(a[i-1]==1) ans+=4;
			if(a[i-1]==2) return puts("Infinite"),0;
		}
	}
	printf("Finite\n%d\n",ans);
}