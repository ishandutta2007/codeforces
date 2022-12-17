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
const int maxn=150+5;
int n,m,a[maxn],b[maxn],d[maxn],ord[maxn];
struct matrix{
	bitset<maxn> a[maxn];
	matrix operator *(matrix B){
		matrix BR;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				BR.a[i][j]=B.a[j][i];
		matrix C;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				C.a[i][j]=(a[i]&BR.a[j]).any();
		return C;
	}
}A,B;
matrix ksm(matrix A,int b){
	matrix ans;
	for(int i=0;i<n;i++) ans.a[i][i]=1;
	while(b){
		if(b%2==1) ans=ans*A;
		A=A*A;
		b/=2;
	}
	return ans;
}
int dis[maxn];
int calc(){
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	dis[n-1]=0;
	q.push(n-1);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<n;i++) if(B.a[i][u]&&dis[i]<0){
			dis[i]=dis[u]+1;
			q.push(i);
		}
	}
	int res=2e9;
	for(int i=0;i<n;i++)
		if(A.a[0][i]&&dis[i]>=0) res=min(res,dis[i]);
	return res;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=m;i++){
		a[i]=readint()-1;
		b[i]=readint()-1;
		d[i]=readint();
	}
	for(int i=1;i<=m;i++) ord[i]=i;
	sort(ord+1,ord+m+1,[](int x,int y){
		return d[x]<d[y];
	});
	for(int i=0;i<n;i++) A.a[i][i]=1;
	for(int i=1;i<=m;i++){
		int t=calc();
		if(t<=d[ord[i]]-d[ord[i-1]]){
			printf("%d\n",d[ord[i-1]]+t);
			return 0;
		}
		A=A*ksm(B,d[ord[i]]-d[ord[i-1]]);
		B.a[a[ord[i]]][b[ord[i]]]=1;
	}
	int t=calc();
	if(t<=n) printf("%d\n",d[ord[m]]+t);
	else printf("Impossible\n");
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}