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
const int maxn=2e5+5;
int n,k,a[maxn];
ll s[maxn+50];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=0;i<=n;i++) s[i]=a[i]=readint();
	for(int i=0;i<=n+50;i++) if(s[i]%2==0){
		s[i+1]+=s[i]/2;
		s[i]=0;
	}
	int l=0;
	while(!s[l]) l++;
	ll y=0;
	for(int i=n+50;i>=l;i--){
		y=y*2+s[i];
		if(abs(y)>2e9){
			printf("0\n");
			return 0;
		}
	}
	int cnt=0;
	for(int i=l;i>=0;i--){
		if(i<=n&&abs(a[i]-y)<=k&&(i<n||a[i]-y)) cnt++;
		y*=2;
		if(abs(y)>2e9) break;
	}
	printf("%d\n",cnt);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}