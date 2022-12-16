#include <stdio.h>
#define MN 200000

int a,b,k;
char ans[MN+5];

int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(a<1||b<2||k==0){
		if(k==0){
			puts("Yes");
			for(int i=1;i<=b;i++)
				putchar('1');
			for(int i=1;i<=a;i++)
				putchar('0');
			putchar('\n');
			for(int i=1;i<=b;i++)
				putchar('1');
			for(int i=1;i<=a;i++)
				putchar('0');
			putchar('\n');
		}else{
			puts("No");
		}
	}else{
		if(k>a+b-2){
			puts("No");
		}else{
			puts("Yes");
			a -= 1;
			b -= 2;
			for(int i=1;i<=a;i++)
				ans[i] = '0';
			for(int i=1;i<=b;i++)
				ans[a+i] = '1';
			putchar('1');
			putchar('1');
			for(int i=1;i<=k-1;i++)
				putchar(ans[i]);
			putchar('0');
			for(int i=k;i<=a+b;i++)
				putchar(ans[i]);
			putchar('\n');
			putchar('1');
			putchar('0');
			for(int i=1;i<=k-1;i++)
				putchar(ans[i]);
			putchar('1');
			for(int i=k;i<=a+b;i++)
				putchar(ans[i]);
			putchar('\n');
		}
	}
}