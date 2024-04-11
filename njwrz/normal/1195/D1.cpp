#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
inline int in(){
	int x=0,f=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-')
		f=-1;
	}while(ch>'9'||ch<'0');
	do{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}while(ch<='9'&&ch>='0');
	return f*x;
}
int main(){
	long long n,a[100001],i,p[100001],d[20],ans=0,t,k;
	n=in();
	for(i=0;i<n;i++)a[i]=in();
	for(k=0;k<n;k++){
		p[k]=0;t=0;
		while(a[k]!=0){
			d[t++]=a[k]%10;a[k]/=10; 
		}
		for(i=0;i<t/2;i++){
			swap(d[i],d[t-i-1]);
		}
		for(i=0;i<t;i++){
			p[k]=p[k]*100+d[i]*11;p[k]%=998244353 ;
		}
		
		ans+=p[k];ans%=998244353 ;
	}
	cout<<(ans*n)%998244353 ; 
	return 0;
}