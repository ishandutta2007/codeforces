#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,ans1,ans2,eve;
int ask(int c,int d){
	cout<<"? "<<c<<" "<<d<<endl;
//	if((22^c)>(843^d)) return 1;
//	if((22^c)<(843^d)) return -1;
//	return 0;
	int opt;cin>>opt;return opt;
} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int sta=ask(0,0);
	for(int i=29;i>=0;i--){
		int k=ask(ans1|(1<<i),ans2|(1<<i));
		if(k==sta){
			if(ask(ans1^(1<<i),ans2)==-1) ans1|=(1<<i),ans2|=(1<<i);
		} 
		else{
			if(k==0){
				if(sta==1) ans2|=(1<<i);
				else ans1|=(1<<i); sta=0;
			}
			else{
				if(k==1) ans2|=(1<<i);
				else(ans1|=(1<<i));
				sta=ask(ans1,ans2);
			}
		}
	}
	cout<<"! "<<ans1<<" "<<ans2<<endl;
	return 0;
}