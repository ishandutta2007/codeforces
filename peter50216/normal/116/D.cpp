#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char in[160][160];
int l[160],r[160];
int cnt[160];
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int c=0;
    for(i=0;i<n;i++){
	scanf("%s",&in[i]);
	for(j=0;j<m;j++)if(in[i][j]=='W')c++;
    }
    if(c==0){
	puts("0");
	return 0;
    }
    int ans=0;
    for(i=0;i<n;i++){
	l[i]=m-1,r[i]=0;
	for(j=0;j<m;j++)if(in[i][j]=='W'){
	    l[i]=min(l[i],j);
	    r[i]=max(r[i],j);
	    cnt[i]++;
	}
    }
    int ni;
    int np=0;
    for(i=0;i<n;i=ni){
	for(j=i+1;j<n;j++)if(cnt[j])break;
	ni=j;
	if(ni!=n){
	    ans+=ni-i;
	    if(i%2==0){
		if(ni%2==0){
		    if(l[ni]>=r[i]){
			ans+=l[ni]-np;
			np=l[ni];
		    }else{
			ans+=r[i]-np;
			ans+=r[i]-l[ni];
			np=l[ni];
		    }
		}else{
		    if(r[ni]>=r[i]){
			ans+=r[ni]-np;
			np=r[ni];
		    }else{
			ans+=r[i]-np;
			np=r[i];
		    }
		}
	    }else{
		if(ni%2==1){
		    if(r[ni]<=l[i]){
			ans+=np-r[ni];
			np=r[ni];
		    }else{
			ans+=np-l[i];
			ans+=r[ni]-l[i];
			np=r[ni];
		    }
		}else{
		    if(l[ni]<=l[i]){
			ans+=np-l[ni];
			np=l[ni];
		    }else{
			ans+=np-l[i];
			np=l[i];
		    }
		}
	    }
	}else{
	    if(i%2==0){
		ans+=r[i]-np;
	    }else{
		ans+=np-l[i];
	    }
	}
    }
    printf("%d\n",ans);
}