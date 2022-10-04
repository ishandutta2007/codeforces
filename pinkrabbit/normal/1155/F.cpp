#include<cstdio>
int n,m,u,c[1<<14],w[14][14],g1[14][1<<14],_g1[14][1<<14],g2[14][1<<14],_g2[14][1<<14],h[14][14][1<<14],_h[14][14][1<<14],f[1<<14],_fi[1<<14],_fj[1<<14],_ft[1<<14];
int au[99],av[99],k;
void e(int u,int v){au[k]=u,av[k++]=v;}
void p(int i,int j,int s){
	if(i==j)return;
	e(j,_h[i][j][s]);
	p(i,_h[i][j][s],s^1<<j);
}
void q(int s){
	if(s==(s&-s))return;
	int i=_fi[s],j=_fj[s];
	if(i==j)e(i,_g1[i][s^_ft[s]]),e(i,_g2[i][s^_ft[s]]);
	else e(i,_g1[i][s^_ft[s]]),e(j,_g1[j][s^_ft[s]]);
	p(i,j,_ft[s]);
	q(s^_ft[s]);
}
int main(){
	scanf("%d%d",&n,&m),u=1<<n;
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y),--x,--y;
		w[x][y]=w[y][x]=1;
	}
	for(int s=1;s<u;++s)c[s]=c[s&(s-1)]+1;
	for(int i=0;i<n;++i)for(int s=1;s<u;++s)if(~s>>i&1)
		for(int j=0;j<n;++j)if(s>>j&1)
			if(w[i][j]){
				if(g1[i][s])g2[i][s]=1,_g2[i][s]=j;
				else g1[i][s]=1,_g1[i][s]=j;
			}
	for(int i=0;i<n;++i)h[i][i][1<<i]=1;
	for(int s=1;s<u;++s)for(int i=0;i<n;++i)for(int j=0;j<n;++j)if((s>>i&1)&&(s>>j&1)&&i!=j)
		for(int k=0;k<n;++k)if((s>>k&1)&&k!=j&&w[j][k])
			if(h[i][k][s^1<<j])h[i][j][s]=1,_h[i][j][s]=k;
	for(int s=0;s<u;++s)f[s]=m+1;
	for(int i=0;i<n;++i)f[1<<i]=0;
	for(int s=3;s<u;++s)if(s!=(s&-s))
		for(int t=(s-1)&s;t;t=(t-1)&s)for(int i=0;i<n;++i)if(t>>i&1)for(int j=i;j<n;++j)if(t>>j&1)
			if(h[i][j][t]&&g1[i][s^t]&&(i!=j?g1[j][s^t]:g2[i][s^t]))
				if(f[s]>f[s^t]+c[t]+1)
					f[s]=f[s^t]+c[t]+1,_fi[s]=i,_fj[s]=j,_ft[s]=t;
	q(u-1);
	printf("%d\n",k);
	for(int i=0;i<k;++i)printf("%d %d\n",au[i]+1,av[i]+1);
}