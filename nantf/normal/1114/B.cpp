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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k;
bool tag[maxn];
ll ans;
struct node{
	int val,id;
	bool operator<(const node &nd)const{
		if(val!=nd.val) return val>nd.val;
		return id<nd.id;
	}
}nd[maxn];
int main(){
	n=read();m=read();k=read();
	FOR(i,1,n) nd[i].val=read(),nd[i].id=i;
	sort(nd+1,nd+n+1);
	FOR(i,1,m*k) ans+=nd[i].val,tag[nd[i].id]=true;
	printf("%I64d\n",ans);
	int tot=1;
	FOR(i,1,n){
		int cnt=0,j=i;
		while(j<=n && cnt<m){
			if(tag[j]) cnt++;
			j++;
		}
		i=j-1;
		if(tot<k) printf("%d ",i),tot++;
	}
}