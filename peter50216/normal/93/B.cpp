#include<stdio.h>
int cnt[105];
int g[105][105];
int main(){
    int n,w,m,i,j;
    scanf("%d%d%d",&n,&w,&m);
    for(i=0;i<n;i++)cnt[i]=m;
    int ii=0;
    for(i=0;i<m;i++){
	int k=n;
	while(k>0){
	    if(cnt[ii]==0)ii++;
	    cnt[ii]--;
	    k--;
	    g[ii][i]++;
	}
    }
    for(i=0;i<n;i++){
	int cc=0;
	for(j=0;j<m;j++)if(g[i][j])cc++;
	if(cc>=3)break;
    }
    if(i<n)puts("NO");
    else{
	puts("YES");
	for(i=0;i<m;i++){
	    bool f=1;
	    for(j=0;j<n;j++)if(g[j][i]){
		if(f)f=0;
		else printf(" ");
		printf("%d %.8lf",j+1,(g[j][i]*(double)w)/m);
	    }
	    puts("");
	}
    }
}