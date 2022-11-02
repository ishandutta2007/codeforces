#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int in[10010];
int main(){
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    if(n%2==0)puts("0");
    else{
	m/=(n+1)/2;
	if(m==0)puts("0");
	else{
	    int ans=1000000000;
	    for(i=0;i<n;i+=2)ans=min(ans,in[i]);
	    printf("%d\n",(int)min((long long)m*k,(long long)ans));
	}
    }
}