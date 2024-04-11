#include<stdio.h>
#include<algorithm>
using namespace std;
int sum2[101000];
int one[101000],oc;
int ooid[101000];
int oid[101000];
int two[101000],tc;
int tid[101000];
int ttid[101000];
int ans[101000];
bool cmpo(int a,int b){return one[a]>one[b];}
bool cmpt(int a,int b){return two[a]>two[b];}
int main(){
    int n,v,i;
    scanf("%d%d",&n,&v);
    for(i=0;i<n;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1){
	    ooid[oc]=i;
	    one[oc++]=b;
	}else{
	    ttid[tc]=i;
	    two[tc++]=b;
	}
    }
    for(i=0;i<oc;i++)oid[i]=i;
    for(i=0;i<tc;i++)tid[i]=i;
    sort(oid,oid+oc,cmpo);
    sort(tid,tid+tc,cmpt);
    sum2[0]=0;
    for(i=1;i<=tc;i++)sum2[i]=sum2[i-1]+two[tid[i-1]];
    int aa=0,a1,a2;
    int s=0;
    for(i=0;i<=oc;i++){
	if(i>v)break;
	int d=s+sum2[min((v-i)/2,tc)];
	if(d>aa){
	    aa=d;
	    a1=i;
	    a2=min((v-i)/2,tc);
	}
	if(i!=oc)s+=one[oid[i]];
    }
    if(aa==0){
	puts("0\n");
	return 0;
    }
    int ac=0;
    for(i=0;i<a1;i++)ans[ac++]=ooid[oid[i]];
    for(i=0;i<a2;i++)ans[ac++]=ttid[tid[i]];
    sort(ans,ans+ac);
    printf("%d\n",aa);
    for(i=0;i<ac;i++)printf("%d%c",ans[i]+1,(i==ac-1)?'\n':' ');
}