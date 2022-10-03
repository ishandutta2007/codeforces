#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MT 405
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
const int lis[30]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
int islk[10001];
int n,q,S,T;
int a[MN],bel[MN];
int lb[MT],rb[MT],add[MT];
int buk[MT][10001];
void clear(int id){
	F(i,lb[id],rb[id])buk[id][a[i]]=0;
}
void rebuild(int id){
	F(i,lb[id],rb[id])a[i]+=add[id];
	add[id]=0;
	F(i,lb[id],rb[id])++buk[id][a[i]];
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	F2(i,0,30)islk[lis[i]]=1;
	scanf("%d%d",&n,&q),S=sqrt(n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)bel[i]=(i-1)/S+1;
	T=bel[n];
	F(i,1,T){
		lb[i]=(i-1)*S+1;
		rb[i]=min(n,i*S);
		rebuild(i);
	}
	while(q--){
		char s[10];
		int l,r,d;
		scanf("%s%d%d",s,&l,&r);
		if(*s=='a'){
			scanf("%d",&d);
			if(bel[l]==bel[r]){
				clear(bel[l]);
				F(i,l,r)a[i]+=d;
				rebuild(bel[l]);
			}else{
				F(i,bel[l]+1,bel[r]-1)add[i]+=d;
				clear(bel[l]);
				F(i,l,rb[bel[l]])a[i]+=d;
				rebuild(bel[l]);
				clear(bel[r]);
				F(i,lb[bel[r]],r)a[i]+=d;
				rebuild(bel[r]);
			}
		}else{
			int ans=0;
			if(bel[l]==bel[r]){
				F(i,l,r)if(islk[a[i]+add[bel[i]]])++ans;
			}else{
				F(i,l,rb[bel[l]])if(islk[a[i]+add[bel[i]]])++ans;
				F(i,lb[bel[r]],r)if(islk[a[i]+add[bel[i]]])++ans;
				F(i,bel[l]+1,bel[r]-1)F2(j,0,30)ans+=(lis[j]-add[i]>=1?buk[i][lis[j]-add[i]]:0);
			}
			printf("%d\n",ans);
		}
	}
}	return 0;
}