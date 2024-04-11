#include<stdio.h>
#include<algorithm>
using namespace std;

int in[110];
bool u[110];
int l[110],lc;

int main(){
    int k,n,i;
    scanf("%d%d",&k,&n);
    int mi=1000000000,ma=-1;
    for(i=1;i<=k;i++)scanf("%d",&in[i]);
    int q;
    int cc=k/n;
    scanf("%d",&q);
    while(q--){
	int s=0;
	for(i=0;i<cc;i++){
	    int t;
	    scanf("%d",&t);
	    u[t]=1;
	    s+=in[t];
	}
	if(s>ma)ma=s;
	if(s<mi)mi=s;
    }
    int c=0;
    for(i=1;i<=k;i++){
	if(!u[i])l[c++]=in[i];
    }
    sort(l,l+c);
    if((k-c)/cc<n){
	int s=0;
	for(i=0;i<cc;i++)s+=l[i];
	if(s>ma)ma=s;
	if(s<mi)mi=s;
	s=0;
	for(i=c-cc;i<c;i++)s+=l[i];
	if(s>ma)ma=s;
	if(s<mi)mi=s;
    }
    printf("%.10lf %.10lf\n",mi/(double)cc,ma/(double)cc);
}