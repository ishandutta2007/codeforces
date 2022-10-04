#include<cstdio>
int m,n,x,k,y,c[10];
int A[100][100],B[100][100],C[100][100];
int main(){
	scanf("%d%d%d%d",&m,&n,&x,&k);
	while(m--) scanf("%d",&y), ++c[y];
	for(int j=1;j<=9;++j){
		for(int i=0;i<k;++i)
			B[(10*i+j)%k][i]+=c[j];
	}
	for(int i=0;i<k;++i) A[i][i]=1;
	for(;n;n>>=1){
		if(n&1){
			for(int i=0;i<k;++i)
				for(int j=0;j<k;++j){
					C[i][j]=0;
					for(int l=0;l<k;++l)
						C[i][j]=(C[i][j]+(long long)A[i][l]*B[l][j])%1000000007;
				}
			for(int i=0;i<k;++i)
				for(int j=0;j<k;++j)
					A[i][j]=C[i][j];
		}
		for(int i=0;i<k;++i)
			for(int j=0;j<k;++j){
				C[i][j]=0;
				for(int l=0;l<k;++l)
					C[i][j]=(C[i][j]+(long long)B[i][l]*B[l][j])%1000000007;
			}
		for(int i=0;i<k;++i)
			for(int j=0;j<k;++j)
				B[i][j]=C[i][j];
	} printf("%d",A[x][0]);
	return 0;
}