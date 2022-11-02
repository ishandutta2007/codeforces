#include<bits/stdc++.h>
#define M 200020
#define LL long long
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
struct data{int K,id;}a[M]; int c[M];
bool cmp(data x,data y){return x.K<y.K;}
int n,now=1,tak,cal=1,last;
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i].K=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp); last=a[1].K;
	for(int i=2;i<=n;last=a[i].K,i++){
		if(now+last==n){
			++tak; for(int j=cal;j<i;j++) c[a[j].id]=tak;
			now=1; cal=i; last=a[i].K; continue;
		}
		if(a[i].K==last) now++;
		else{puts("Impossible\n");return 0;}
	}
	if(now+last==n){tak++;for(int j=cal;j<=n;j++) c[a[j].id]=tak;}
	else{puts("Impossible");return 0;} puts("Possible");
	for(int i=1;i<=n;i++) printf("%d ",c[i]); puts("");
	return 0;
}