#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111;
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
int n,a[maxn],b[maxn],ans=-1;
map<vector<int>,int> mp;
inline int bitcnt(int x){
	int c=0;
	for(;x;x&=x-1) c++;
	return c;
} 
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,0,32767){
		FOR(j,1,n) b[j]=bitcnt((a[j]&32767)^i);
		vector<int> v;
		FOR(j,2,n) v.push_back(b[1]-b[j]);
		mp[v]=i;
	}
	FOR(i,0,32767){
		FOR(j,1,n) b[j]=bitcnt((a[j]>>15)^i);
		vector<int> v;
		FOR(j,2,n) v.push_back(b[j]-b[1]);
		if(mp.count(v)){ans=(i<<15)|mp[v];break;}
	}
	printf("%d\n",ans);
}