#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int r,a1,a2,a3,a4,inv;
int d[105][405],ans[105][105][105];

int mod(int x){return x>=cys?x-cys:x;}

int power(int x,int p){
	int ret=1;
	for(;p;p>>=1,x=1ll*x*x%cys) if(p&1) ret=1ll*ret*x%cys;
	return ret;
}

void gauss(int id,int n){
	int p;
	for(int i=0;i<=2*n;i++){
		p=i;
		for(int j=i+1;j<=2*n;j++) if(abs(d[j][i])>abs(d[p][i])) p=j;
		if(p!=i) for(int j=i;j<=4*n+2;j++) swap(d[i][j],d[p][j]);
		for(int j=i+1;j<=2*n;j++){
			int tmp=1ll*d[j][i]*power(d[i][i],cys-2)%cys;
			for(int k=i;k<=4*n+2;k++) d[j][k]=mod(d[j][k]+cys-1ll*tmp*d[i][k]%cys);
		}
	}
	for(int i=2*n;i>=0;i--){
		for(int j=i+1;j<=2*n;j++) for(int k=1;k<=2*n+2;k++) d[i][2*n+k]=mod(d[i][2*n+k]+cys-1ll*ans[id][j][k]*d[i][j]%cys);
		for(int j=1;j<=2*n+2;j++) ans[id][i][j]=1ll*d[i][2*n+j]*power(d[i][i],cys-2)%cys;
	}
}

int main(){
	r=readint(); a1=readint(); a2=readint(); a3=readint(); a4=readint(); inv=power(a1+a2+a3+a4,cys-2);
	for(int i=r;i>=-r;i--){
		memset(d,0,sizeof(d));
		int m=sqrt(r*r-i*i);
		for(int j=-m;j<=m;j++){
			if(j!=-m) d[j+m][j+m-1]=mod(d[j+m][j+m-1]+1ll*a1*inv%cys);
			if(j!=m) d[j+m][j+m+1]=mod(d[j+m][j+m+1]+1ll*a3*inv%cys);
			d[j+m][4*m+2]=mod(d[j+m][4*m+2]+cys-1);
			d[j+m][j+m]=cys-1;
		}
		if(i!=r){
			int tmp=sqrt(r*r-(i+1)*(i+1));
			for(int j=max(-m,-tmp);j<=min(m,tmp);j++)
				for(int k=-tmp;k<=tmp;k++) d[j+m][k+m]=mod(d[j+m][k+m]+1ll*a2*inv%cys*ans[i+r+1][j+tmp][k+tmp+1]%cys);
			for(int j=max(-m,-tmp);j<=min(m,tmp);j++) d[j+m][4*m+2]=mod(d[j+m][4*m+2]+cys-1ll*a2*inv%cys*ans[i+r+1][j+tmp][2*tmp+2]%cys);
		}
		if(i!=-r){
			int tmp=sqrt(r*r-(i-1)*(i-1));
			for(int j=max(-m,-tmp);j<=min(m,tmp);j++)
				d[j+m][3*m+j+1]=mod(d[j+m][3*m+j+1]+cys-1ll*a4*inv%cys);
		}
		gauss(i+r,m);
	}
	for(int i=1;i<=2*r;i++){
		int m=sqrt(r*r-(i-r)*(i-r)),tmp=sqrt(r*r-(i-r-1)*(i-r-1));
		for(int j=-m;j<=m;j++){
			for(int k=max(-m,-tmp);k<=min(m,tmp);k++)
				ans[i][j+m][2*m+2]=mod(ans[i][j+m][2*m+2]+1ll*ans[i][j+m][k+m+1]*ans[i-1][k+tmp][2*tmp+2]%cys);
		}
	}
	printf("%d\n",ans[r][r][2*r+2]);
	return 0;
}