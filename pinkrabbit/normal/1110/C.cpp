#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
int q,a;
int main(){
	scanf("%d",&q);
	F(i,1,q){
		scanf("%d",&a);
		if((a+1)&a){
			int x=1;
			while(x<=a)x<<=1;
			printf("%d\n",x-1);
		}
		else{
			int y=0;
			for(int x=2;x*x<=a;++x)
				if(a%x==0){y=x;break;}
			if(!y)puts("1");
			else printf("%d\n",a/y);
		}
	}
	return 0;
}