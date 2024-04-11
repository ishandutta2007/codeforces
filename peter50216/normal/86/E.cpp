#include<stdio.h>
#include<stdlib.h>
bool randbit(){
    static int r=-1;
    static int c=-1;
    if(c==-1){
	c=15;
	r=rand();
    }
    bool x=(r>>c)&1;
    c--;
    return x;
}
int c[110];
int n;
int a[110];
int tmp[110];
int tt[110];
inline void gen(){
    for(int i=1;i<n;i++)c[i]=randbit();
    c[0]=1;
}
inline void add(int* a,int* b){
    for(int i=0;i<n;i++)a[i]^=b[i];
}
inline void shift(int* a){
    int k=a[n-1];
    for(int i=n-1;i>0;i--)a[i]=a[i-1];
    a[0]=0;
    if(k)add(a,c);
}
inline void mul(int* ar,int *b){
    int i;
    for(i=0;i<n;i++){
	tmp[i]=b[i];
	tt[i]=0;
    }
    for(i=0;i<n;i++){
	if(ar[i])add(tt,tmp);
	shift(tmp);
    }
    for(i=0;i<n;i++)ar[i]=tt[i];
}
inline void squ(int* ar){
    int i;
    for(i=0;i<n;i++){
	tmp[i]=ar[i];
	tt[i]=0;
    }
    for(i=0;i<n;i++){
	if(ar[i])add(tt,tmp);
	shift(tmp);
    }
    for(i=0;i<n;i++)ar[i]=tt[i];
}
inline void pow(int* a,long long b){
    int i;
    if(b==0){
	a[0]=1;
	for(i=1;i<n;i++)a[i]=0;
	return;
    }
    if(b==1)return;
    int tmp[110];
    for(i=0;i<n;i++)tmp[i]=a[i];
    pow(a,b/2);
    squ(a);
    if(b%2)mul(a,tmp);
}
inline bool is1(int* a){
    int i;
    for(i=0;i<n;i++)if(a[i]!=(i==0))return 0;
    return 1;
}
bool np[1000000];
long long pr[100000];
int pc;
inline void pre(){
    long long i,j;
    for(i=2;i<1000000;i++)if(!np[i]){
	pr[pc++]=i;
	for(j=i*i;j<1000000;j+=i)np[j]=1;
    }
}
inline void tox(int* a){
    for(int i=0;i<n;i++)a[i]=0;
    a[1]=1;
}
inline bool solve(){
    int i;
    long long k=(1ll<<n)-1;
    tox(a);
    pow(a,k);
    if(!is1(a))return 0;
    long long t=k;
    for(i=0;i<pc&&pr[i]*pr[i]<=t;i++){
	if(t%pr[i]==0){
	    while(t%pr[i]==0)t/=pr[i];
	    tox(a);
	    pow(a,k/pr[i]);
	    if(is1(a))return 0;
	}
    }
    if(t>1){
	tox(a);
	pow(a,k/t);
	if(is1(a))return 0;
    }
    return 1;
}
int main(){
    srand(514);
    pre();
    scanf("%d",&n);
    while(1){
	gen();
	if(solve()){
	    for(int i=0;i<n;i++)printf("%d%c",c[n-1-i],(i==n-1)?'\n':' ');
	    for(int i=0;i<n;i++)printf("1%c",(i==n-1)?'\n':' ');
	    break;
	}
    }
}