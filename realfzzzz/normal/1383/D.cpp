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
const int maxn=250+5;
int n,m,r[maxn],c[maxn],t[maxn*maxn],a[maxn][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		int a=read();
		r[i]=max(r[i],a);
		c[j]=max(c[j],a);
	}
	for(int i=0;i<n;i++) t[r[i]]=1;
	for(int i=0;i<m;i++) t[c[i]]|=2;
	int x=-1,y=-1;
	queue<int> q;
	for(int i=n*m;i>0;i--){
		if(t[i]&1) x++;
		if(t[i]>>1&1) y++;
		if(t[i]&1)
			for(int j=y-1;j>=0;j--) q.push(m*x+j);
		if(t[i]>>1&1)
			for(int j=x-1;j>=0;j--) q.push(m*j+y);
		if(t[i]) a[x][y]=i;
		else{
			a[q.front()/m][q.front()%m]=i;
			q.pop();
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}