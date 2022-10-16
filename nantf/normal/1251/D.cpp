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
struct seg{
	int l,r;
	bool operator<(const seg &s)const{return l<s.l;}
}s[maxn];
int t,n,tmp[maxn],tl;
ll sum;
bool check(int x){
	ll tot=0;
	int rem=(n+1)/2;
	tl=0;
	FOR(i,1,n){
		if(s[i].r<x) tot+=s[i].l;
		if(s[i].l>=x) tot+=s[i].l,rem--;
		if(s[i].r>=x && s[i].l<x) tmp[++tl]=s[i].l;
	}
	rem=max(rem,0);
	if(tl<rem) return false;
	sort(tmp+1,tmp+tl+1);
	FOR(i,1,tl-rem) tot+=tmp[i];
	FOR(i,tl-rem+1,tl) tot+=x;
	return tot<=sum;
}
int main(){
	t=read();
	while(t--){
		n=read();sum=read();
		FOR(i,1,n) s[i].l=read(),s[i].r=read();
		int l=1,r=1e9;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
}