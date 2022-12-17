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
int n,q;
char s[maxn];
const int inf=2e9;
inline void cmin(int& x,int y){
	x=min(x,y);
}
struct matrix{
	int a[4][4];
	matrix operator *(matrix B){
		matrix C;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++){
			C.a[i][j]=inf;
			for(int k=0;k<4;k++)
				if(a[i][k]<inf&&B.a[k][j]<inf)
					cmin(C.a[i][j],a[i][k]+B.a[k][j]);
		}
		return C;
	}
};
const int trans[][4]={{1,1,3,3},{0,2,2,3},{0,1,-1,-1}};
matrix get(int c){
	matrix A;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) A.a[i][j]=inf;
	for(int i=0;i<3;i++) for(int j=0;j<4;j++)
		if(trans[i][j]>=0) cmin(A.a[j][trans[i][j]],i!=c);
	return A;
}
struct node{
	int l,r;
	node* ch[2];
	matrix A;
	void pushup(){
		A=ch[0]->A*ch[1]->A;
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			A=get(s[r]-'a');
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x,int k){
		if(l==r){
			A=get(k);
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	scanf("%s",s+1);
	rt=new node(1,n);
	while(q--){
		int pos=readint();
		char c[5];
		scanf("%s",c);
		rt->modify(pos,c[0]-'a');
		int ans=inf;
		for(int i=0;i<4;i++) cmin(ans,rt->A.a[0][i]);
		printf("%d\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}