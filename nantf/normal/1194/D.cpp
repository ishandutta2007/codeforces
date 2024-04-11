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
int t,n,k,sg[maxn],cnt[maxn];
int main(){
	t=read();
	while(t--){
		n=read();k=read();
		if(!n){puts("Bob");continue;}
		else if(k%3==0){
			int rem=n%(k+1);
			if(rem==k) puts("Alice");
			else puts(rem%3?"Alice":"Bob");
		}
		else puts(n%3?"Alice":"Bob");
	}
}