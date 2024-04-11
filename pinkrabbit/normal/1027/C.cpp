#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef double ld;
#define Luogu Judging
int n;
int a[1000001];
int c[10001];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ld Ans=99999999999;
		int X,Y,ok=0;
		scanf("%d",&n);
		F(i,1,n) scanf("%d",a+i), ++c[a[i]];
		F(i,1,n) if(c[a[i]]>=4){
			printf("%d %d %d %d\n",a[i],a[i],a[i],a[i]);
			ok=1;
			break;
		}
		if(ok){
			F(i,1,n) --c[a[i]];
			continue;
		}
		sort(a+1,a+n+1);
		int lst=0;
		F(i,1,n) if(c[a[i]]>=2){
			if(lst&&a[i]!=lst){
				if(Ans>(ld)(lst+a[i])*(lst+a[i])/(lst*a[i]))
					Ans=(ld)(lst+a[i])*(lst+a[i])/(lst*a[i]),
					X=lst, Y=a[i];
			}
			lst=a[i];
		}
		printf("%d %d %d %d\n",X,X,Y,Y);
		F(i,1,n) --c[a[i]];
	}
	return 0;
}