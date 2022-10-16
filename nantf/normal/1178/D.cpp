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
int n,m,cnt;
bool use[maxn];
bool check(int x){
	if(x==1) return false;
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
int main(){
	n=m=read();
	while(!check(m)) m++;
	cnt=m-n;
	printf("%d\n",m);
	FOR(i,1,n){
		printf("%d %d\n",i,i%n+1);
		if(cnt && !use[i]){
			int to=i%n+1;
			to=to%n+1;
			while(use[to]) to=to%n+1;
			use[i]=use[to]=true;
			printf("%d %d\n",i,to);
			cnt--;
		}
	}
}