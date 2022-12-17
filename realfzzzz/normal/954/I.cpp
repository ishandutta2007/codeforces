#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=1.25e5+5;
struct cp{
	double re,im;
	cp(double re=0,double im=0):re(re),im(im){}
	cp operator +(cp b){
		return cp(re+b.re,im+b.im);
	}
	cp operator -(cp b){
		return cp(re-b.re,im-b.im);
	}
	cp operator *(cp b){
		return cp(re*b.re-im*b.im,re*b.im+im*b.re);
	}
};
const double pi=acos(-1);
typedef vector<cp> poly;
int rev[maxn*4];
cp w[maxn*4],w2[maxn*4];
poly FFT(poly F,bool flag){
	int n=F.size();
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			cp t=F[k+i]*(flag?w[i+k-j]:w2[i+k-j]);
			F[k+i]=F[k]-t;
			F[k]=F[k]+t;
		}
	if(!flag) for(int i=0;i<n;i++) F[i].re/=n;
	return F;
}
int n,m;
char S[maxn],T[maxn];
struct dsu{
	int fa[6];
	dsu(){
		for(int i=0;i<6;i++) fa[i]=i;
	}
	void find(int x){
		if(fa[x]!=x) find(fa[x]);
		fa[x]=fa[fa[x]];
	}
}s[maxn];
int ans[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",S,T);
	n=strlen(S);
	m=strlen(T);
	int len=1;
	while(len<n+m-1) len*=2;
	for(int i=1;i<len;i++) rev[i]=rev[i>>1]>>1|((i&1)?len>>1:0);
	for(int i=1;i<len;i*=2){
		w[i]=1;
		cp wn(cos(pi/i),sin(pi/i));
		for(int j=1;j<i;j++) w[i+j]=w[i+j-1]*wn;
	}
	for(int i=1;i<len;i*=2){
		w2[i]=1;
		cp wn(cos(pi/i),-sin(pi/i));
		for(int j=1;j<i;j++) w2[i+j]=w2[i+j-1]*wn;
	}
	for(int i=0;i<6;i++) for(int j=0;j<6;j++){
		poly F(len),G(len);
		for(int k=0;k<n;k++) F[k]=cp(S[k]=='a'+i,0);
		for(int k=0;k<m;k++) G[m-1-k]=cp(T[k]=='a'+j,0);
		F=FFT(F,1);
		G=FFT(G,1);
		for(int k=0;k<len;k++) F[k]=F[k]*G[k];
		F=FFT(F,0);
		for(int k=0;k<n-m+1;k++) if(abs(F[k+m-1].re)>1e-3){
			s[k].find(i);
			s[k].find(j);
			if(s[k].fa[i]!=s[k].fa[j]){
				ans[k]++;
				s[k].fa[s[k].fa[i]]=j;
			}
		}
	}
	for(int i=0;i<n-m+1;i++) printf("%d ",ans[i]);
	return 0;
}