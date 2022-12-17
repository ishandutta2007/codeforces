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
const int m=100;
int f[m][m],c[m][m],d[m][m];
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	for(int i=3;i<m;i++) for(int j=0;j<=i;j++){
		int k=i-j;
		f[j][k]=2e9;
		for(int x=0;x<=j;x++) for(int y=0;y<=k;y++)
			if((y<k||x+y<j)&&(y||x+y>k)&&max(f[x+y][j-x],f[j+k-x-y][x])+1<f[j][k]){
				f[j][k]=max(f[x+y][j-x],f[j+k-x-y][x])+1;
				c[j][k]=x;
				d[j][k]=y;
			}
	}
	int n=read();
	vector<int> a(n),b;
	for(int i=1;i<=n;i++) a[i-1]=i;
	while(a.size()+b.size()>2){
		int a2,b2;
		if(a.size()+b.size()<m){
			a2=c[a.size()][b.size()];
			b2=d[a.size()][b.size()];
		}
		else{
			a2=a.size()/2;
			b2=b.size()/2;
		}
		printf("? %d ",a2+b2);
		for(int i=0;i<a2;i++) printf("%d ",a[i]);
		for(int i=0;i<b2;i++) printf("%d ",b[i]);
		printf("\n");
		fflush(stdout);
		char s[5];
		scanf("%s",s);
		vector<int> aa,bb;
		if(s[0]=='Y'){
			for(int i=0;i<a2;i++) aa.push_back(a[i]);
			for(int i=0;i<b2;i++) aa.push_back(b[i]);
			for(int i=a2;i<(int)a.size();i++) bb.push_back(a[i]);
		}
		else{
			for(int i=a2;i<(int)a.size();i++) aa.push_back(a[i]);
			for(int i=b2;i<(int)b.size();i++) aa.push_back(b[i]);
			for(int i=0;i<a2;i++) bb.push_back(a[i]);
		}
		a=aa;
		b=bb;
	}
	for(int i:b) a.push_back(i);
	printf("! %d\n",a[0]);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	if(s[1]=='('){
		printf("! %d\n",a[1]);
		fflush(stdout);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}