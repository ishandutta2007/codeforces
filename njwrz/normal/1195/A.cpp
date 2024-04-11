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
int f[1001];
int main(){
	int n,m,i;
	n=in();m=in();
	int x;
	for(i=0;i<n;i++){
		x=in();
		f[x]++;
	}
	int ans=n;
	n=(n+1)/2;
	for(i=0;i<=1000;i++){
		if(f[i]%2==0){
			n-=f[i]/2;
		}else{
			n-=f[i]/2;ans--;
		}
	}
	ans+=n;
	cout<<ans<<endl;
	return 0;
}