#include<stdio.h>
#include<algorithm>
using namespace std;
int id[5010];
int cnt[5010];
bool m[5010][5010];
char tmp[5010];
inline bool cmp(int a,int b){return cnt[a]>cnt[b];}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%s",&tmp);
	for(j=0;j<n;j++){
	    m[i][j]=(tmp[j]=='1');
	    cnt[i]+=m[i][j];
	}
	id[i]=i;
    }
    sort(id,id+n,cmp);
    for(i=0;i<n;i++){
	int x=id[i];
	if(cnt[x]==n-i-1)continue;
	int m1=-1,m2=-1;
	for(j=0;j<n;j++){
	    if(m[j][x] && cnt[j]<=cnt[x]){
		m1=j;
		break;
	    }
	}
	for(j=0;j<n;j++){
	    if(m[x][j]&&m[j][m1]){
		m2=j;break;
	    }
	}
	printf("%d %d %d\n",x+1,m2+1,m1+1);
	break;
    }
    if(i==n)puts("-1");
}