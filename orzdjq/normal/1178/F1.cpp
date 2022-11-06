#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=505;
const int Maxm=1000005;
const LL mod=998244353;
int n,m,a[Maxm];
int Mn[Maxn],Mx[Maxn];
LL ans=1;
LL dp[Maxn][Maxn],mn[Maxn][Maxn];
int Nxt[Maxm];
LL g(int i,int j){
	if (i>j) return 1;
	return dp[i][j];
}
void Solve(int l,int r){
//	cout<<"S"<<l<<' '<<r<<endl;
	if (l>r) return;
	vector<int> V;
	for (int p=l;p<=r;p=Mx[a[p]]+1){
		//cout<<p<<endl;
		V.pb(a[p]);
	}
	int N=V.size();
	for (int i=0;i<=N;i++){
		for (int j=0;j<=N;j++) dp[i][j]=0;
		dp[i][i]=1;
		if (i) dp[i][i-1]=1;
	}
	for (int i=0;i<N;i++){
		mn[i][i]=i;
		for (int j=i+1;j<N;j++){
			if (V[j]<V[mn[i][j-1]]){
				mn[i][j]=j;
			}
			else{
				mn[i][j]=mn[i][j-1];
			}
		}
	}
	for (int i=2;i<=N;i++){
		for (int j=0;j<N;j++){
			int k=j+i-1;
			if (k>=N) continue;
			LL c1=0,c2=0;
			int p=mn[j][k];
			for (int l=j;l<=p;l++){
				c1+=g(j,l-1)*g(l,p-1);
				c1%=mod;
			}
			for (int r=p;r<=k;r++){
				c2+=g(p+1,r)*g(r+1,k);
				c2%=mod;
			}
			dp[j][k]=c1*c2%mod;
		//	cout<<j<<' '<<k<<' '<<p<<' '<<dp[j][k]<<' '<<c1<<' '<<c2<<endl;
		}
	}
	ans*=dp[0][N-1];
//	cout<<"SSS"<<' '<<dp[0][N-1]<<endl;
	ans%=mod;
	for (int p=l;p<=r;p=Mx[a[p]]+1){
		int tmp=p;
		while (tmp!=Mx[a[p]]){
			int nx=Nxt[tmp];
			Solve(tmp+1,nx-1);
			tmp=nx;
		}
	}
}
int nxt[Maxn];
int main(){
	scanf("%d %d",&n,&m);
	for (int i=0;i<Maxn;i++) Mn[i]=1e9,Mx[i]=-1e9;
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		Mn[a[i]]=min(Mn[a[i]],i);
		Mx[a[i]]=max(Mx[a[i]],i);
	}
	for (int i=1;i<=n;i++) nxt[i]=m+1;
	for (int i=m;i>=1;i--){
		Nxt[i]=nxt[a[i]];
		nxt[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		for (int j=Mn[i];j<=Mx[i];j++){
			//cout<<i<<' '<<Mn[a[i]]<<' '<<Mx[a[i]]<<endl;
			if (a[j]<i){
				//cout<<j<<' '<<i<<endl;
				printf("0\n");
				return 0;
			}
		}
	}
	Solve(1,m);
	printf("%I64d\n",ans);
	return 0;
}