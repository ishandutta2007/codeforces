#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

const double eps=1e-12;

int n,m;

int dcmp(double x){
	if(x>eps)
		return 1;
	return x<-eps?-1:0;
}

int readint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

struct data{
	double a,b;
	bool operator<(const data &c)const{
		return b<c.b;
	}
}d[200005];

int main(){
	double ans=0;
	n=readint(); m=readint();
	for(int i=1;i<=n;i++)
		d[i].a=readint();
	for(int i=1;i<=n;i++){
		d[i].b=readint();
		d[i].b-=m;
		if(!dcmp(d[i].b))
			ans+=d[i].a;
	}
	sort(d+1,d+n+1);
	int l=0,r=n+1;
	for(int i=1;i<=n;i++){
		if(dcmp(d[i].b)>0){
			r=i;
			break;
		}
	}
	for(int i=n;i>0;i--){
		if(dcmp(d[i].b)<0){
			l=i;
			break;
		}
	}
	while(l>0&&r<=n){
		if(-d[l].a*d[l].b<d[r].a*d[r].b){
			ans+=d[l].a-d[l].a*d[l].b/d[r].b;
			d[r].a+=d[l].a*d[l].b/d[r].b;
			l--;
		}
	    else{
			ans+=d[r].a-d[r].a*d[r].b/d[l].b;
			d[l].a+=d[r].a*d[r].b/d[l].b;
			r++;
		}
	}
	printf("%.12lf\n",ans);
	return 0;
}