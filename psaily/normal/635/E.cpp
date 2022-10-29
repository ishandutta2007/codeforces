#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
int d,n,m;
ll ans;
struct points{
	int x,p;
	bool operator < (const points&_)const{
		return x<_.x;
	}
}A[maxn];
int nxt[maxn];
void init(){
	nxt[m-1]=m;
	for(int i=m-2;i>=0;i--){
		if(A[i+1].p<A[i].p)nxt[i]=i+1;
		else{
			int cur=i+1;
			while(A[nxt[cur]].p>A[i].p)cur=nxt[cur];
			nxt[i]=nxt[cur];
		}
	}
}
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&A[i].x,&A[i].p);
	A[0]=(points){0,inf},A[++m]=(points){d,0};
	sort(A,A+m+1);
	init();
	int now=n,add=0;
	for(int i=0;i<m;i++){
		//printf("now=%d\n",now);
		if(now<0){puts("-1");return 0;}
		int to=nxt[i];
		add=A[to].x-A[i].x;
		if(add>n)add=n;
		if(add>now){
			ans+=1ll*(add-now)*A[i].p;
			now=add;
		}
		now-=A[i+1].x-A[i].x;
	}
	printf("%I64d\n",now<0?-1:ans);
	return 0;
}