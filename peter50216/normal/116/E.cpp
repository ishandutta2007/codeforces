#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod=1000003;
char in[500010];
inline int pow(int a,int b){
    if(b==0)return 1;
    if(b==1)return a%mod;
    long long r=pow(a,b/2);
    r=(r*r)%mod;
    if(b%2)r=(r*a)%mod;
    return r;
}
int n,m;
inline char f(int x,int y){return in[x*m+y];}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",&in[i*m]);
    int ans=1;
    for(i=0;i<n;i++){
	int f1=0,f2=0;
	for(j=0;j<m;j++){
	    char c=f(i,j);
	    if(c=='1'||c=='2'){
		if(j%2==0)f1=1;
		else f2=1;
	    }else if(c=='3'||c=='4'){
		if(j%2==0)f2=1;
		else f1=1;
	    }
	}
	if(f1&&f2)ans=0;
	else if(!f1&&!f2)ans=(ans*2)%mod;
    }
    for(j=0;j<m;j++){
	int f1=0,f2=0;
	for(i=0;i<n;i++){
	    char c=f(i,j);
	    if(c=='1'||c=='4'){
		if(i%2==0)f1=1;
		else f2=1;
	    }else if(c=='2'||c=='3'){
		if(i%2==0)f2=1;
		else f1=1;
	    }
	}
	if(f1&&f2)ans=0;
	else if(!f1&&!f2)ans=(ans*2)%mod;
    }
    printf("%d\n",ans);
}