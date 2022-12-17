#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
inline void write(ll x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e3+5;
int n,m;
ll a[maxn],b[maxn];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
struct node{
	int l,r;
	node* ch[2];
	ll d=0;
	void pushup(){
		d=gcd(ch[0]->d,ch[1]->d);
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,ll k){
		if(l==r){
			d=k;
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
}*rt1[maxn],*rt2[maxn];
bool vis1[maxn],vis2[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=m;i++) b[i]=read();
		for(int i=1;i<=n;i++){
			rt1[i]=new node(1,m);
			for(int j=1;j<=m;j++)
				rt1[i]->modify(j,a[i]/gcd(a[i],b[j]));
		}
		for(int i=1;i<=m;i++){
			rt2[i]=new node(1,n);
			for(int j=1;j<=n;j++)
				rt2[i]->modify(j,b[i]/gcd(b[i],a[j]));
		}
		for(int i=1;i<=n;i++) vis1[i]=0;
		for(int i=1;i<=m;i++) vis2[i]=0;
		int s1=n,s2=m;
		while(s1&&s2){
			bool flag=1;
			for(int i=1;i<=n;i++)
				if(!vis1[i]&&rt1[i]->d>1){
					vis1[i]=1;
					for(int j=1;j<=m;j++)
						rt2[j]->modify(i,0);
					s1--;
					flag=0;
					break;
				}
			if(!flag) continue;
			for(int i=1;i<=m;i++)
				if(!vis2[i]&&rt2[i]->d>1){
					vis2[i]=1;
					for(int j=1;j<=n;j++)
						rt1[j]->modify(i,0);
					s2--;
					flag=0;
					break;
				}
			if(flag) break;
		}
		if(!s1||!s2){
			printf("NO\n");
			continue;
		}
		printf("YES\n%d %d\n",s1,s2);
		for(int i=1;i<=n;i++) if(!vis1[i]){
			write(a[i]);
			printf(" ");
		}
		printf("\n");
		for(int i=1;i<=m;i++) if(!vis2[i]){
			write(b[i]);
			printf(" ");
		}
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}