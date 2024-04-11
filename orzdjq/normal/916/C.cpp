#include<bits\stdc++.h>
using namespace std;
const int Maxn=200005;
bool isp[Maxn];
void _init(){
	memset(isp,true,sizeof(isp));
	isp[0]=isp[1]=false;
	for (int i=2;i<Maxn;i++){
		if (isp[i]){
			for (int j=i+i;j<Maxn;j+=i){
				isp[j]=false;
			}
		}
	}
}
int main(){
	_init();
	int n,m;
	scanf("%d %d",&n,&m);
	int k=n-1;
	while (!isp[k]) k++;
	printf("%d %d\n",k,k);
	for (int i=1;i<n-1;i++){
		printf("%d %d 1\n",i,i+1);
	} 
	printf("%d %d %d\n",n-1,n,k-n+2);
	int nowi=1,nowj=3;
	for (int j=0;j<(m-n+1);j++){
		printf("%d %d 1000000000\n",nowi,nowj);
		nowj++;
		if (nowj>n) nowi++,nowj=nowi+2;
	}
	return 0;
}