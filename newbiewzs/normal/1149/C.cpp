#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
char a[N*2];
int x,y;
int n,m;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int maxx[N*4];
int ml[N*4],mil[N*4],mr[N*4],mir[N*4];
int ld[N*4],rd[N*4],zd[N*4];
int summ[N*4];
void update(int u){
	summ[u]=summ[ls]+summ[rs];
	ml[u]=max(ml[ls],summ[ls]+ml[rs]);
	mr[u]=max(mr[rs],summ[rs]+mr[ls]);
	mil[u]=min(mil[ls],summ[ls]+mil[rs]);
	mir[u]=min(mir[rs],summ[rs]+mir[ls]);
	ld[u]=max(ld[ls],max(ld[rs]-summ[ls],zd[ls]+ml[rs]));
	if(u==15){
		new char;
	}
	rd[u]=max(rd[rs],max(summ[rs]+rd[ls],zd[rs]-mir[ls]));
	zd[u]=max(summ[rs]+zd[ls],zd[rs]-summ[ls]);
	maxx[u]=max(max(maxx[ls],maxx[rs]),max(ld[rs]-mir[ls],rd[ls]+ml[rs]));
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		if(u==14){
			new char;
		}
		if(k==-1){
			summ[u]=-1;
			mil[u]=mir[u]=-1;
			ml[u]=mr[u]=0;
		}
		else{
			summ[u]=1;
			ml[u]=mr[u]=1;
			mil[u]=mir[u]=0;
		}
		rd[u]=ld[u]=zd[u]=maxx[u]=1;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	update(u);
}
int main(){
	n=read();m=read();
	scanf("%s",a+1);
	int l=strlen(a+1);
	for(int i=1;i<=l;i++){
		if(a[i]==')')add(1,1,l,i,-1);
		else add(1,1,l,i,1);
	}
	printf("%d\n",maxx[1]);
	for(int i=1;i<=m;i++){
		x=read();y=read();
		swap(a[x],a[y]);
		if(a[x]==')')add(1,1,l,x,-1);
		else add(1,1,l,x,1);
		if(a[y]==')')add(1,1,l,y,-1);
		else add(1,1,l,y,1);
		printf("%d\n",maxx[1]);
	}
	return 0;
}