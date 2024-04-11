#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,blo,N;
int bl[300005],a[200005],lf[1005],rg[1005],num[300005],numb[1005],pnum[300005],pnumb[1005];
ll preb[1005],pre[300005],val[300005],valb[300005],ans[300005];

void change(int x){
	int b=bl[x];
	val[x]+=x,valb[b]+=x,num[x]++,numb[b]++;
	for(int i=1;i<=m;i++) preb[i]=preb[i-1]+valb[i],pnumb[i]=pnumb[i-1]+numb[i];
	pre[lf[b]]=val[lf[b]],pnum[lf[b]]=num[lf[b]];
	for(int i=lf[b]+1;i<=rg[b];i++) pre[i]=pre[i-1]+val[i],pnum[i]=pnum[i-1]+num[i];
}

ll ask(int l,int r){
	int lb=bl[l],rb=bl[r];
	if(lb==rb) return pre[r]-pre[l]+val[l];
	return preb[rb-1]-preb[lb]+pre[r]+valb[lb]-pre[l]+val[l];
}

int asknum(int l,int r){
	int lb=bl[l],rb=bl[r];
	if(lb==rb) return pnum[r]-pnum[l]+num[l];
	return pnumb[rb-1]-pnumb[lb]+pnum[r]+numb[lb]-pnum[l]+num[l];
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),chkmax(N,a[i]);
	blo=sqrt(N);
	for(int i=1;i<=N;i+=blo) lf[++m]=i,rg[m]=min(N,i+blo-1);
	for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1];
		if(a[i]<=blo){
			for(int j=1;j<i;j++) ans[i]+=a[i]%a[j]+a[j]%a[i];
		}
		else{
			ans[i]+=1ll*(i-1)*a[i];
			for(int j=1,k;j<=a[i];j=k+1){
				k=a[i]/(a[i]/j);
				ans[i]-=1ll*ask(j,k)*(a[i]/j);
			}
			ans[i]+=ask(1,N);
			for(int j=a[i];j<=N;j+=a[i]) ans[i]-=1ll*asknum(j,N)*a[i];
		}
		change(a[i]);
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}