#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,sum;
int a[100001];
void Getint(int &x){
	x = 0;char c;
	while(isdigit(c = getchar()))
		x = x * 10 + c - '0';
}
int main(){
	Getint(n);
	For(i,1,n)Getint(a[i]);
	For(i,1,n)a[i]--;
	sum = 0;
	For(i,1,n){
		sum += a[i];
		if(sum&1)printf("1\n");
		else printf("2\n"); 
	}
	return 0;
}