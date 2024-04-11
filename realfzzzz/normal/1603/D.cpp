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
const int maxn=1e5+5;
bool np[maxn];
vector<int> p;
int phi[maxn];
ll s[maxn];
const int maxs=350,S=337;
ll s1[maxn][maxs],s2[maxn][maxs];
ll c(int l,int r){
	if(l<=S) return s1[r][l];
	else{
		int x=r/(r/l);
		return s2[r][r/l-1]+s[r/l]*(x-l+1);
	}
}
ll f[18][maxn];
int q[maxn],hd,tl;
int get(int k,int a,int b){
	int l=b+1,r=maxn+1;
	while(l<r){
		int mid=l+(r-l)/2;
		if(f[k-1][a]+c(a+1,mid)>=f[k-1][b]+c(b+1,mid)) r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	phi[1]=1;
	for(int i=2;i<maxn;i++){
		if(!np[i]){
			phi[i]=i-1;
			p.push_back(i);
		}
		for(int j:p){
			if(1ll*i*j>=maxn) break;
			np[i*j]=1;
			if(i%j==0){
				phi[i*j]=phi[i]*j;
				break;
			}
			else phi[i*j]=phi[i]*phi[j];
		}
	}
	for(int i=2;i<maxn;i++) s[i]=s[i-1]+phi[i];
	for(int i=1;i<maxn;i++){
		int l=S+1;
		while(l<=i){
			int r=i/(i/l);
			s2[i][i/l]=s[i/l]*(r-l+1);
			l=r+1;
		}
		for(int j=1;j<=i/(S+1);j++) s2[i][j]+=s2[i][j-1];
		s1[i][S+1]=s2[i][i/(S+1)];
		for(int j=min(i,S);j>0;j--) s1[i][j]=s1[i][j+1]+s[i/j];
	}
	for(int i=1;i<maxn;i++) f[1][i]=c(1,i);
	for(int i=2;i<=17;i++){
		hd=0;
		tl=1;
		for(int j=1;j<maxn;j++){
			while(tl-hd>1&&get(i,q[hd],q[hd+1])<=j) hd++;
			f[i][j]=f[i-1][q[hd]]+c(q[hd]+1,j);
			while(tl-hd>1&&get(i,q[tl-2],q[tl-1])>=get(i,q[tl-1],j)) tl--;
			q[tl++]=j;
		}
	}
	int T=readint();
	while(T--){
		int n,k;
		n=readint();
		k=readint();
		printf("%lld\n",(k<=17?f[k][n]:0)+n);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}