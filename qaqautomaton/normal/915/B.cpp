#include<bits/stdc++.h>
using namespace std;
void chkmin(int &a,int b){
    if(a>b)a=b;
}
int main(){
	int n,p,l,r;
	scanf("%d%d%d%d",&n,&p,&l,&r);
	int ans=0;
	if(p>r){
	    ans=p-r;
	    p=r;
	}
	else if(p<l){
	    ans=l-p;
	    p=l;
	}
	if(l==1&&r==n)printf("0\n");
	else if(l==1)printf("%d\n",ans+r-p+1);
	else if(r==n)printf("%d\n",ans+p-l+1);
	else printf("%d\n",ans+(r-l)+min(p-l,r-p)+2);
	return 0;
}