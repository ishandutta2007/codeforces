#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int k;
const int mod=1000000007;
char a[1010],b[1010];
inline void rev(char* c){
    reverse(c,c+strlen(c));
}
inline void p1(char* c){
    c[0]++;
    int i;
    for(i=0;;i++){
	if(c[i]=='9'+1){
	    c[i]-=10;
	    if(c[i+1]==0)c[i+1]='1',c[i+2]=0;
	    else c[i+1]++;
	}else break;
    }
}
inline int add(int a,int b){
    a+=b;
    return a>=mod?a-mod:a;
}
inline int sub(int a,int b){
    a-=b;
    return a<0?a+mod:a;
}
inline int mul(long long a,long long b){return (a*b)%mod;}
int dp[1010][1010];
int lc[1010];
int pow[1010];
inline void rundp(){
    int i,j;
    pow[0]=1;
    for(i=1;i<=1000;i++)pow[i]=mul(pow[i-1],10);
    for(i=0;i<k;i++)dp[1][i]=2;
    dp[1][k]=0;
    for(i=2;i<=1000;i++){
	for(j=0;j<=k;j++){
	    dp[i][j]=0;
	    if(j<k)dp[i][j]=add(dp[i][j],mul(2,pow[i-1]));
	    else dp[i][j]=add(dp[i][j],mul(2,dp[i-1][0]));
	    if(j==k)dp[i][j]=add(dp[i][j],mul(8,dp[i-1][j]));
	    else dp[i][j]=add(dp[i][j],mul(8,dp[i-1][j+1]));
	    //if(i<=3)printf("%d %d %d\n",i,j,dp[i][j]);
	}
    }
    lc[1]=0;
    for(i=2;i<=1000;i++){
	lc[i]=lc[i-1];
	for(j=1;j<=9;j++){
	    lc[i]=add(lc[i],(j==4||j==7)?dp[i-1][0]:dp[i-1][k]);
	}
    }
}
inline bool isl(char c){return c=='4'||c=='7';}
inline int solve(char* c){
    int n=strlen(c);
    int i,j;
    int ret=lc[n-1];
    int lu=-10000;
    bool f=0;
    for(i=0;i<n;i++){
	for(j=(i==0?1:0);j<c[i]-'0';j++){
	    bool ff=f;
	    int p=lu;
	    if(j==4||j==7){
		if(i-lu<=k)ff=1;
		p=i;
	    }
	    if(ff){
		ret=add(ret,pow[n-i-1]);
	    }else{
		p=i-p;
		if(p>k)p=k;
		ret=add(ret,dp[n-i-1][p]);
	    }
	}
	if(isl(c[i])){
	    if(i-lu<=k)f=1;
	    lu=i;
	}
    }
    //printf("%s: %d\n",c,ret);
    return ret;
}
int main(){
    int q;
    scanf("%d%d",&q,&k);
    rundp();
    while(q--){
	scanf("%s%s",a,b);
	rev(b);
	p1(b);
	rev(b);
	printf("%d\n",sub(solve(b),solve(a)));
    }
}