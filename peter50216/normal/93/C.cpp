#include<stdio.h>
int n;
int ans[100][5];//kind, k, x, y, z
int tmp[100][5];
int ac=1000;
int r[26];
int up;
void dfs(int np){
   // printf("np=%d\n",np);
    int i,j,k,l;
    if(r[np]==n){
	ac=np;
	for(i=0;i<np;i++)for(j=0;j<5;j++){
	    ans[i][j]=tmp[i][j];
	}
	return;
    }
    //puts("!");
    if(np>up)return;
    for(j=0;j<=np;j++){
	for(k=0;k<=np;k++){
	    for(l=8;l>1;l>>=1){
		r[np+1]=r[j]+l*r[k];
		if(r[np+1]<=n){
		    tmp[np][0]=2;
		    tmp[np][1]=l;
		    tmp[np][2]=np+1;
		    tmp[np][3]=j;
		    tmp[np][4]=k;
		    dfs(np+1);
		    if(ac<1000)return;
		}
	    }
	}
    }
    for(j=0;j<=np;j++){
	for(l=8;l>1;l>>=1){
	    r[np+1]=l*r[j];
	    if(r[np+1]<=n){
		tmp[np][0]=1;
		tmp[np][1]=l;
		tmp[np][2]=np+1;
		tmp[np][3]=j;
		dfs(np+1);
		if(ac<1000)return;
	    }
	}
    }
    for(j=0;j<=np;j++){
	for(k=0;k<=np;k++){
	    r[np+1]=r[j]+r[k];
	    if(r[np+1]<=n){
		tmp[np][0]=0;
		tmp[np][2]=np+1;
		tmp[np][3]=j;
		tmp[np][4]=k;
		dfs(np+1);
		if(ac<1000)return;
	    }
	}
    }
}
int main(){
    scanf("%d",&n);
    if(n==1){
	puts("0");
	return 0;
    }
    ac=1000;
    r[0]=1;
    for(up=0;ac==1000;up++){
	//printf("up=%d\n",up);
	dfs(0);
    }
    printf("%d\n",ac);
    for(int i=0;i<ac;i++){
	printf("lea e%cx, [",ans[i][2]+'a');
	if(ans[i][0]==0){
	    printf("e%cx + e%cx",ans[i][3]+'a',ans[i][4]+'a');
	}else if(ans[i][0]==1){
	    printf("%d*e%cx",ans[i][1],ans[i][3]+'a');
	}else if(ans[i][0]==2){
	    printf("e%cx + %d*e%cx",ans[i][3]+'a',ans[i][1],ans[i][4]+'a');
	}
	printf("]\n");
    }
}