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
int l,r,cnt[10];
bool check(int x){
	while(x) cnt[x%10]++,x/=10;
	bool ans=true;
	FOR(i,0,9) if(cnt[i]>=2) ans=false;
	FOR(i,0,9) cnt[i]=0;
	return ans;
}
int main(){
	l=read();r=read();
	FOR(i,l,r) if(check(i)) return printf("%d\n",i),0;
	puts("-1");
}