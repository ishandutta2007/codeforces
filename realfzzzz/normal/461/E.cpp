#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxm=1e5+5;
ll n;
int m;
char t[maxm];
int sz=1,last=0,len[maxm*2],link[maxm*2],nxt[maxm*2][4];
void extend(int c){
	int cur=sz++;
	len[cur]=len[last]+1;
	int p=last;
	while(p>=0&&!nxt[p][c]){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p>=0){
		int q=nxt[p][c];
		if(len[q]==len[p]+1) link[cur]=q;
		else{
			int clone=sz++;
			link[clone]=link[q];
			memcpy(nxt[clone],nxt[q],sizeof(nxt[0]));
			len[clone]=len[p]+1;
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[cur]=link[q]=clone;
		}
	}
	last=cur;
}
int f[4][maxm*2];
void dfs(int u){
	if(f[0][u]>=0) return;
	for(int i=0;i<4;i++) if(nxt[u][i]) dfs(nxt[u][i]);
	for(int i=0;i<4;i++){
		f[i][u]=nxt[u][i]?2e9:0;
		for(int j=0;j<4;j++) if(nxt[u][j])
			f[i][u]=min(f[i][u],f[i][nxt[u][j]]+1);
	}
}
struct matrix{
	ll a[4][4];
	matrix operator *(matrix B){
		matrix C;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++){
			C.a[i][j]=n;
			for(int k=0;k<4;k++)
				C.a[i][j]=min(C.a[i][j],a[i][k]+B.a[k][j]);
		}
		return C;
	}
};
matrix ksm(matrix A,ll b){
	matrix ans;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) ans.a[i][j]=i==j?0:n;
	while(b){
		if(b%2==1) ans=ans*A;
		A=A*A;
		b/=2;
	}
	return ans;
}
matrix A[60];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",t+1);
	m=strlen(t+1);
	link[0]=-1;
	for(int i=1;i<=m;i++) extend(t[i]-'A');
	memset(f,-1,sizeof(f));
	dfs(0);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) A[0].a[i][j]=f[i][nxt[0][j]]+1;
	for(int i=1;i<60;i++) A[i]=A[i-1]*A[i-1];
	ll ans=0;
	matrix B;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) B.a[i][j]=i==j?0:n;
	for(int i=59;i>=0;i--){
		matrix C=A[i]*B;
		ll res=n+1;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++) res=min(res,C.a[j][k]);
		if(res<n){
			ans+=1ll<<i;
			B=C;
		}
	}
	printf("%lld\n",ans+1);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}