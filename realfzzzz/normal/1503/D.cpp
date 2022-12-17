// LUOGU_RID: 96314439
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
const int maxn=2e5+5;
int n,c[maxn];
bool d[maxn];
int mn[maxn],mx[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++){
		int a,b;
		a=read();
		b=read();
		if((a<=n)^(b>n)){
			printf("-1\n");
			return 0;
		}
		if(a<=n) c[a]=b-n;
		else{
			c[b]=a-n;
			d[b]=1;
		}
	}
	mn[0]=n+1;
	for(int i=1;i<=n;i++) mn[i]=min(mn[i-1],c[i]);
	for(int i=n;i>0;i--) mx[i]=max(mx[i+1],c[i]);
	int ans=0,s=0,l=0,lst1=n+1,lst2=n+1;
	for(int i=1;i<=n;i++){
		if(c[i]<lst1){
			if(c[i]<lst2){
				s+=d[i]^(lst1<lst2);
				lst1<lst2?lst1:lst2=c[i];
			}
			else{
				s+=!d[i];
				lst1=c[i];
			}
		}
		else{
			if(c[i]<lst2){
				s+=d[i];
				lst2=c[i];
			}
			else{
				printf("-1\n");
				return 0;
			}
		}
		if(mn[i]>mx[i+1]){
			ans+=min(s,i-l-s);
			s=0;
			l=i;
			lst1=lst2=n+1;
		}
	}
	printf("%d\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}