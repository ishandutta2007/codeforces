#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;
int n,m,px[1<<5],nx[1<<5],py[1<<5],ny[1<<5],f[32][2][2][20][20][20][20];

void upd(int &x,int y){x=(x+y)%mod;}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		if (x>0) px[1<<i]+=x; else nx[1<<i]-=x;
		if (y>0) py[1<<i]+=y; else ny[1<<i]-=y;
	}
	for (int i=1;i<1<<n;++i){
		int j=i&(-i);
		px[i]=px[j]+px[i^j];
		nx[i]=nx[j]+nx[i^j];
		py[i]=py[j]+py[i^j];
		ny[i]=ny[j]+ny[i^j];
	}
	int d1=px[(1<<n)-1],d2=nx[(1<<n)-1],d3=py[(1<<n)-1],d4=ny[(1<<n)-1];
	if (!d1||!d2||!d3||!d4){puts("0"); return 0;}
	f[0][0][0][0][0][0][0]=1;
	for (int i=0;i<30;++i)
		for (int fx=0;fx<2;++fx)
			for (int fy=0;fy<2;++fy)
				for (int j1=0;j1<d1;++j1)
					for (int j2=0;j2<d2;++j2)
						for (int j3=0;j3<d3;++j3)
							for (int j4=0;j4<d4;++j4)
								for (int k=0;k<1<<n;++k){
									int k1=j1+px[k],k2=j2+nx[k],k3=j3+py[k],k4=j4+ny[k];
									if ((k1&1)==(k2&1)&&(k3&1)==(k4&1)){
										int gx=((k1&1)>(m>>i&1))||((k1&1)==(m>>i&1)&&fx);
										int gy=((k3&1)>(m>>i&1))||((k3&1)==(m>>i&1)&&fy);
										upd(f[i+1][gx][gy][k1>>1][k2>>1][k3>>1][k4>>1],f[i][fx][fy][j1][j2][j3][j4]);
									}
								}
	printf("%d\n",(f[30][0][0][0][0][0][0]-1+mod)%mod);
	
	return 0;
}