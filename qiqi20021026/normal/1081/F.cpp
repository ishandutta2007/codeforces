#include<bits/stdc++.h>
 
using namespace std;
 
#define N 500
 
int n,tot,a[N],b[N];
int c[N];
char s[N];
 
int main(){
	scanf("%d%d",&n,&tot);
	for (int i=1;i<=n;++i) c[i]=s[i]-'0';
	for (int i=1,t=tot;i<n;++i){
		bool flag=0;
		for (int j=1;j<=20;++j){
			printf("? %d %d\n",i+1,n);
			fflush(stdout);
			int x; scanf("%d",&x);
			if (x==n-t){
				for (int k=1;k<=i;++k){
					b[k]^=1;
				}
			}
			else{
				if (!flag){
					flag=1;
					int sum=n-t-x;
					for (int k=1;k<i;++k){
						sum+=b[k]==1; sum-=b[k]==0;
					}
					a[i]=(sum<0)^b[i];
					b[i]=sum<0;
				}
			}
			t=x;
		}
		if (!flag){
			b[i]=0;
			for (int k=1;k<i;++k){
				b[i]+=b[k]==0; b[i]-=b[k]==1;
			}
			a[i]=b[i]=b[i]>0;
		}
	}
	a[n]=tot;
	for (int i=1;i<n;++i) a[n]-=a[i];
	printf("! "); for (int i=1;i<=n;++i) putchar(a[i]+'0'); puts("");
	
	return 0;
}