#include<stdio.h>
#include<algorithm>
using namespace std;
char in[40][40];
int n,m;
int cnt[40][40];
int pl[40][40];
int all[40][4][2];
int aa[15];
int now[15];
int used[7];
int ans;
bool domu[70];
int dom[70];
int mk[300];
inline int inv(int a){
    return ((a&7)<<3)+(a>>3);
}
void dfs(int np){
//    printf("%d\n",np);
    int i,j;
    if(np==14){
	ans++;
	for(i=0;i<14;i++){
	    aa[i]=now[i];
	    //printf("%d ",now[i]);
	}
	//puts("");
	//for(i=1;i<=28;i++)printf("%d,%d ",dom[i],inv(dom[i]));
//	puts("");
	//puts("!");
//	scanf(" ");
	return;
    }
    for(i=0;i<=6;i++){
	if(used[i]==2)continue;
//	printf("np=%d i=%d\n",np,i);
	for(j=0;j<4;j++){
	    int x=all[np][j][0],y=all[np][j][1];
	    int c=mk[in[x][y]];
//    printf("%d %d %d %d\n",x,y,c,dom[c]);
	    if(dom[c]==0)dom[c]+=i+1;
	    else{
		int k=dom[c]+((i+1)<<3);
		int r=inv(k);
		if(domu[r]||domu[k]){
		    j--;
		    break;
		}
		dom[c]=k;
		domu[r]=domu[k]=1;
	    }
	   // if(c==14)printf("np=%d i=%d j=%d dom[c]=%d\n",np,i,j,dom[c]);
	}
//	printf("j=%d\n",j);
	if(j==4){
	    used[i]++;
	    now[np]=i;
//	    printf("np=%d i=%d\n",np,i);
	    dfs(np+1);
	    used[i]--;
	}
	if(j==4)j--;
	for(;j>=0;j--){
	    int x=all[np][j][0],y=all[np][j][1];
	    int c=mk[in[x][y]];
	    if(dom[c]<8)dom[c]-=i+1;
	    else{
		int r=inv(dom[c]);
		domu[r]=domu[dom[c]]=0;
		dom[c]-=((i+1)<<3);
	    }
	    //printf("np=%d i=%d j=%d c=%d dom[c]=%d\n",np,i,j,c,dom[c]);
	}
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)scanf("%s",in[i]);
    int cc=1,k,l;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]!='.'&&cnt[i][j]==0){
	int q=0;
	for(k=0;k<2;k++)for(l=0;l<2;l++){
	    cnt[i+k][j+l]=cc;
	    all[cc-1][q][0]=i+k;
	    all[cc-1][q][1]=j+l;
	    q++;
	}
	cc++;
    }
    int z=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]!='.'&&!mk[in[i][j]]){
	mk[in[i][j]]=++z;
//	printf("%d %c\n",z,in[i][j]);
    }
    ans=0;
    dfs(0);
    printf("%d\n",ans);
    for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	    if(in[i][j]=='.')printf(".");
	    else printf("%d",aa[cnt[i][j]-1]);
	}
	puts("");
    }
}