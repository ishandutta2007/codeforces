#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int t,n,a[maxn],k;
int main(){
	t=read();
	while(t--){
		n=read();k=0;MEM(a,0); 
		while(n){
			a[++k]=sqrt(2*n);
			while(a[k]*(a[k]-1)<=2*n) a[k]++;
			while(a[k]*(a[k]-1)>2*n) a[k]--;
			n-=a[k]*(a[k]-1)/2;
		}
		FOR(i,1,k){
			printf("1");
			FOR(j,1,a[i]-a[i+1]) printf("3");
		}
		printf("7\n");
	}
}