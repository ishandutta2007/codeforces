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
int n,a[maxn],al,b[maxn],bl;
ll s[maxn];
deque<int> q1,q2;
inline ll ask(int tp,int i,int j,int k){
	printf("%d %d %d %d\n",tp,i,j,k);
	fflush(stdout);
	return read();
}
inline bool cmp(int x,int y){
	return s[x]>s[y];
}
int main(){
	n=read();
	FOR(i,3,n) if(ask(2,1,2,i)==-1) a[++al]=i;
	else b[++bl]=i;
	FOR(i,3,n) s[i]=ask(1,1,2,i);
	sort(a+1,a+al+1,cmp);
	sort(b+1,b+bl+1,cmp);
	if(al){
		q1.push_back(a[1]);
		FOR(i,2,al){
			if(ask(2,1,q1.front(),a[i])==-1) q1.push_front(a[i]);
			else q1.push_back(a[i]);
		}
	}
	if(bl){
		q2.push_back(b[1]);
		FOR(i,2,bl){
			if(ask(2,1,q2.front(),b[i])==-1) q2.push_front(b[i]);
			else q2.push_back(b[i]);
		}
	}
	printf("0 1 ");
	FOR(i,0,al-1) printf("%d ",q1[i]);
	printf("2 ");
	FOR(i,0,bl-1) printf("%d ",q2[i]);
	fflush(stdout);
}