#include<bits/stdc++.h>
using namespace std;
int x,y;
long long r;
int main(){
	scanf("%I64d",&r);
	r-=1;
	int sp=sqrt(r);
	for(int i=1;i<=sp;i++){
		if(r%i==0){
			if((r/i-i-1)%2==0&&(r/i-i-1)>0){
				printf("%d %I64d\n",i,(r/i-i-1)/2);
				return 0;
			}
		}
	}
	printf("NO\n");
}