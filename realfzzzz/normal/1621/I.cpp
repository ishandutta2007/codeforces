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
int n,q,b[7][maxn];
int s[maxn],s2[maxn],tp,l[maxn],l2[maxn];
void op(int* c,int* d){
	tp=0;
	for(int i=1;i<=n;i++){
		while(tp&&c[i]<s[tp-s2[tp]+1]) tp%=s2[tp];
		if(!tp||c[i]>s[tp-s2[tp]+1]) s2[tp+1]=tp+1;
		else s2[tp+1]=s2[tp];
		s[++tp]=c[i];
		if(tp%s2[tp]==0){
			l[i]=i-s2[tp]+1;
			l2[i]=i-tp+1;
		}
		else{
			l[i]=l[i-s2[tp]]+s2[tp];
			l2[i]=l2[i-s2[tp]]+s2[tp];
		}
	}
	for(int i=n;i>0;i--)
		if(i==n||l2[i+1]==i+1) l2[i]=l[i];
	int cnt=0;
	for(int i=1;i<=n&&cnt<n;i++)
		for(int j=l2[i];j<=i&&cnt<n;j++) d[++cnt]=c[j];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) b[0][i]=readint();
	for(int i=1;i<=6;i++) op(b[i-1],b[i]);
	q=readint();
	while(q--){
		int i,j;
		i=min(readint(),6ll);
		j=readint();
		printf("%d\n",b[i][j]);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}