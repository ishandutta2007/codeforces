#include<cstdio>
#include<algorithm>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,ansll=-1000000000,ansrr=1000000000;
int a[100001];
char b[100009];
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	scanf("%s",b+1);
	F(i,5,n){
		if(b[i-4]==b[i-3]&&b[i-3]==b[i-2]&&b[i-2]==b[i-1]){
			if(b[i-1]=='0'){
				int x=max(max(max(max(a[i],a[i-1]),a[i-2]),a[i-3]),a[i-4]);
				if(b[i]=='1'){
					//l > max(a 1~5)
					ansll=max(ansll,x+1);
				}
			}
			else{
				int x=min(min(min(min(a[i],a[i-1]),a[i-2]),a[i-3]),a[i-4]);
				if(b[i]=='0'){
					//r < min(a 1~5)
					ansrr=min(ansrr,x-1);
				}
			}
		}
	}
	printf("%d %d",ansll,ansrr);
	return 0;
}