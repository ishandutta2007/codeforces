#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s=0;
	char c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
const int N=1e5+55;
int n,m,a[N];
int f[N],g[N];
int C(int x){
	if(x<=1)return 0;
	return (x*(x-1))/2;
}
int coss;
int tong[N];
int head,tail;
void change(int l,int r){
	while(tail<r){
		tail++;
		coss-=C(tong[a[tail]]);
		tong[a[tail]]++;
		coss+=C(tong[a[tail]]);
	}
	while(tail>r){
		coss-=C(tong[a[tail]]);
		tong[a[tail]]--;
		coss+=C(tong[a[tail]]);
		tail--;
	}
	while(head<l){
		coss-=C(tong[a[head]]);
		tong[a[head]]--;
		coss+=C(tong[a[head]]);
		head++;
	}
	while(head>l){
		head--;
		coss-=C(tong[a[head]]);
		tong[a[head]]++;
		coss+=C(tong[a[head]]);
	}
}
#define mid ((l+r)>>1)
void cdq(int l,int r,int L,int R){
	if(l>r || L>R)return ;
	int jl;
	for(int i=L;i<=R && i<mid;i++){
		change(i+1,mid);
		if(g[mid]>f[i]+coss and i!=mid){
			g[mid]=f[i]+coss;
			jl=i;
		}
	}
	cdq(l,mid-1,L,jl);
	cdq(mid+1,r,jl,R);
}
signed main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)f[i]=2e15;
	for(int i=1;i<=m;i++){
		for(int k=1;k<=n;k++)g[k]=2e15;
		cdq(1,n,0,n);
		for(int k=1;k<=n;k++)f[k]=g[k];
	}
	cout<<f[n];
	return 0;
}