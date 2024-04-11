#include<stdio.h>
#include<algorithm>
using namespace std;
int in[101000];
int id[101000];
int nid[101000];
int to[101000];
int out[201000][2],oc=0;
inline bool isl(int n){
    while(n){
	if(n%10==4||n%10==7)n/=10;
	else return 0;
    }
    return 1;
}
inline bool cmp(int a,int b){return in[a]<in[b];}
int main(){
    int n,i,p=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d",&in[i]);
	if(isl(in[i]))p=i;
	id[i]=i;
    }
    stable_sort(id,id+n,cmp);
    for(i=0;i<n;i++)if(id[i]!=i)break;
    if(i==n){
	puts("0");
	return 0;
    }
    if(p==-1){
	puts("-1");
	return 0;
    }
    for(i=0;i<n;i++){
	to[i]=i;
	nid[i]=i;
    }
    int pp=p;
    for(i=0;i<n;i++){
	if(id[i]==pp)continue;
	if(nid[i]==id[i])continue;
	if(i!=p){
	    out[oc][0]=i;
	    out[oc][1]=p;
	    oc++;//	    printf("%d %d\n",i+1,p+1);
	    swap(nid[i],nid[p]);
	    to[nid[i]]=i;to[nid[p]]=p;
	    p=i;
	}
	int r=to[id[p]];
	if(r!=p){
	    out[oc][0]=p;
	    out[oc][1]=r;
	    oc++;
	    swap(nid[p],nid[r]);
	    to[nid[p]]=p;to[nid[r]]=r;
	    p=r;
	}
    }
    printf("%d\n",oc);
    for(i=0;i<oc;i++)printf("%d %d\n",out[i][0]+1,out[i][1]+1);
}