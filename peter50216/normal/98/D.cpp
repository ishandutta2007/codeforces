#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int in[30];
int out[1050000][2];
int oc;
int n;
int pre[30];
int cnt[30][2];
inline int cntf(int np,int b){
    if(cnt[np][b]!=-1)return cnt[np][b];
    if(np==n)return cnt[np][b]=0;
    if(!b)return cnt[np][b]=cntf(pre[np]+1,b)*2+(pre[np]-np+1);
    else{
	int w1=cntf(np+1,0)*2+1;
	int w2=cntf(pre[np]+1,0)*2+cntf(pre[np]+1,1)+(pre[np]-np+1)*2;
	return cnt[np][b]=min(w1,w2);
    }
}
inline void move(int a,int b,int c,bool base,int np){
    if(np==n)return;
    if(base){
	int d1=cntf(np,1);
	int d2=cntf(np+1,0)*2+1;
	if(d1==d2){
	    move(a,c,b,false,np+1);
	    out[oc][0]=a;
	    out[oc][1]=b;
	    oc++;
	    move(c,b,a,false,np+1);
	}else{
	    move(a,b,c,false,pre[np]+1);
	    for(int i=np;i<=pre[np];i++){
		out[oc][0]=a;
		out[oc][1]=c;
		oc++;
	    }
	    move(b,a,c,false,pre[np]+1);
	    for(int i=np;i<=pre[np];i++){
		out[oc][0]=c;
		out[oc][1]=b;
		oc++;
	    }
	    move(a,b,c,true,pre[np]+1);
	}
    }else{
	move(a,c,b,false,pre[np]+1);
	for(int i=np;i<=pre[np];i++){
	    out[oc][0]=a;
	    out[oc][1]=b;
	    oc++;
	}
	move(c,b,a,false,pre[np]+1);
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d",&in[i]);
    }
    pre[n-1]=n-1;
    for(i=n-2;i>=0;i--){
	if(in[i]==in[i+1])pre[i]=pre[i+1];
	else pre[i]=i;
    }
    memset(cnt,-1,sizeof(cnt));
    oc=0;
    move(1,3,2,true,0);
    printf("%d\n",oc);
    for(i=0;i<oc;i++)printf("%d %d\n",out[i][0],out[i][1]);
}