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
mt19937 rnd(time(0));
const int maxn=(1<<18)+5;
int n,cnt[maxn];
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	n=(1<<read())-1;
	for(int i=0;i<420;i++){
		int u,v,w;
		do{
			u=rnd()%n+1;
			v=rnd()%n+1;
			w=rnd()%n+1;
		}while(u==v||v==w||u==w);
		printf("? %d %d %d\n",u,v,w);
		fflush(stdout);
		cnt[read()]++;
	}
	int mx=0,mx2=0;
	for(int i=1;i<=n;i++)
		if(cnt[i]>cnt[mx]){
			mx2=mx;
			mx=i;
		}
		else if(cnt[i]>cnt[mx2]) mx2=i;
	for(int i=1;i<=n;i++) if(i!=mx&&i!=mx2){
		printf("? %d %d %d\n",mx,mx2,i);
		fflush(stdout);
		if(read()==i){
			printf("! %d\n",i);
			fflush(stdout);
			break;
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}