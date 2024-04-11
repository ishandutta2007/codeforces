#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 500005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,k,t;
int v[MN],a[MM],b[MM],q[MM];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),k=0;
		F(i,1,n*3)v[i]=1;
		F(i,1,m){
			scanf("%d%d",a+i,b+i),q[i]=0;
			if(v[a[i]]&&v[b[i]])q[i]=1,v[a[i]]=0,v[b[i]]=0,++k;
		}
		t=n;
		if(k>=n){puts("Matching");F(i,1,m)if(q[i]&&t)printf("%d ",i),--t;puts("");}
		else{puts("IndSet");F(i,1,n*3)if(v[i]&&t)printf("%d ",i),--t;puts("");}
	}
	return 0;
}