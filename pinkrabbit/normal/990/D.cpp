#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,a,b;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(n==1) return 0*puts("YES\n0");
	if(n==2){
		if(a==b) return 0*puts("NO");
		if(a==1) return 0*puts("YES\n01\n10");
		return 0*puts("YES\n00\n00");
	}
	if(n==3){
		if(a==1&&b==1) return 0*puts("NO");
		if(a==1&&b==2) return 0*puts("YES\n001\n001\n110");
		if(a==1&&b==3) return 0*puts("YES\n011\n101\n110");
		if(a==2&&b==1) return 0*puts("YES\n010\n100\n000");
		if(a==3&&b==1) return 0*puts("YES\n000\n000\n000");
		if(a>=2&&b>=2) return 0*puts("NO");
	}
	if(a==1&&b==1){
		puts("YES");
		F(i,1,n){
			F(j,1,n){
				if(j==i+1||j==i-1) printf("1");
				else printf("0");
			}
			puts("");
		}
		return 0;
	}
	if(a>=2&&b>=2) return 0*puts("NO");
	puts("YES");
	if(a==1){
		int k=n-b+1;
		F(i,1,n){
			F(j,1,n){
				if(i==j) printf("0");
				else{
					if((j==i+1||j==i-1)&&i<=k&&j<=k) printf("0"); 
					else printf("1");
				}
			}
			puts("");
		}
	}
	else{
		int k=n-a+1;
		F(i,1,n){
			F(j,1,n){
				if(i==j) printf("0");
				else{
					if((j==i+1||j==i-1)&&i<=k&&j<=k) printf("1");
					else printf("0");
				}
			}
			puts("");
		}
	}
	return 0;
}