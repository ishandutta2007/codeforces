#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		if(i&1)printf("I hate ");
		else printf("I love ");
		if(i==n)printf("it");
		else printf("that ");
	}
	return 0;
}