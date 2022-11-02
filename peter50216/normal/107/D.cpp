#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod=12345;
const int N = 123+2;
int in[1010];
char cr[1010];
bool isone[1000];
bool ism[1010];
int mym[1010];
struct XD{
    int num[N][N];
    int n;
    XD(){memset(num,0,sizeof(num));}
    XD operator*(const XD& b)const{
	int i,j,k;
	XD x;
	for(i=0;i<n;i++)for(j=0;j<n;j++)for(k=0;k<n;k++){
	    x.num[i][k]=(x.num[i][k]+num[i][j]*b.num[j][k])%mod;
	}
	x.n=n;
	return x;
    }
    void print(){
	printf("n=%d\n",n);
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)printf("%d ",num[i][j]);
	    puts("");
	}
    }
}a,ans,mul;
inline int lcm(int a,int b){return a*b/__gcd(a,b);}
int sinl[1000];
int dl[1000];
int bk[1000];
int rig[1000];
inline int hash(int n){
    int a=1,ret=0,i;
    for(i=0;i<n;i++){
	ret+=a*dl[i];
	a*=mym[sinl[i]];
    }
    return ret;
}
inline int pow(int a,long long b){
    if(b==0)return 1;
    if(b==1)return a;
    int t=pow(a,b/2);
    t=(t*t)%mod;
    if(b%2)t=(t*a)%mod;
    return t;
}
int main(){
    long long n;
    int c,i,j;
    scanf("%I64d%d",&n,&c);
    int onec=0;
    int allm=1;
    for(i=0;i<1000;i++)mym[i]=1;
    for(i=0;i<c;i++){
	char tmp[3];
	scanf("%s%d",tmp,&in[i]);
	cr[i]=tmp[0];
	if(in[i]==1){
	    c--;i--;
	    if(isone[tmp[0]]==0){
		isone[tmp[0]]=1;
		onec++;
	    }
	}else{
	    allm=lcm(allm,in[i]);
	    mym[cr[i]]=lcm(mym[cr[i]],in[i]);
	}
    }
    if(allm==1){
	printf("%d\n",pow(onec,n));
	return 0;
    }
    int cc=0;
    for(i=0;i<c;i++){
	if(isone[cr[i]]){
	    swap(cr[i],cr[c-1]);
	    swap(in[i],in[c-1]);
	    i--;c--;
	}else if(!ism[cr[i]]){
	    ism[cr[i]]=1;
	    bk[cr[i]]=cc;
	    sinl[cc++]=cr[i];
	}
    }
    int tmt=1;
    for(i=0;i<1000;i++)tmt*=mym[i];
    a.n=tmt;
    //printf("tmt=%d\n",tmt);
    for(i=0;i<a.n;i++)a.num[i][i]=onec;
    for(i=0;i<tmt;i++){
	int ii=i;
	for(j=0;j<cc;j++){
	    dl[j]=ii%mym[sinl[j]];
	    ii/=mym[sinl[j]];
	}
	for(j=0;j<cc;j++){
	    dl[j]=(dl[j]+1)%mym[sinl[j]];
	    int r=hash(cc);
	    a.num[r][i]=1;
	    dl[j]=(dl[j]+mym[sinl[j]]-1)%mym[sinl[j]];
	}
    }
    //printf("%d\n",a.n);
    ans.n=a.n;
    for(i=0;i<a.n;i++)ans.num[i][i]=1;
    while(n){
//	ans.print();
	if(n%2)ans=a*ans;
	a=a*a;
	n/=2;
    }
    int aaa=0;
    for(i=0;i<tmt;i++){
	int ii=i;
	for(j=0;j<cc;j++){
	    dl[j]=ii%mym[sinl[j]];
	    ii/=mym[sinl[j]];
	}
	memset(rig,0,sizeof(rig));
	for(j=0;j<c;j++){
	    //printf("i=%d j=%d %d %d\n",i,j,dl[bk[cr[j]]],in[j]);
	    if(dl[bk[cr[j]]]%in[j]==0)rig[cr[j]]=1;
	}
	for(j=0;j<cc;j++)if(!rig[sinl[j]])break;
	if(j==cc)aaa=(aaa+ans.num[i][0])%mod;
    }
    printf("%d\n",aaa);
}