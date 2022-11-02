#include<stdio.h>
int mi[1000],ma[1000];
int main(){
    int n,s,i,j;
    scanf("%d%d",&n,&s);
    int l=0,r=0;
    for(i=0;i<n;i++){
	scanf("%d%d",&mi[i],&ma[i]);
	l+=mi[i];r+=ma[i];
    }
    if(s>=l&&s<=r){
	for(i=0;i<n;i++){
	    while(ma[i]>mi[i]&&r>s){
		r--;ma[i]--;
	    }
	}
	puts("YES");
	for(i=0;i<n;i++)printf("%d%c",ma[i],(i==n-1)?'\n':' ');
    }else puts("NO");
}