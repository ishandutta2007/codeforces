#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000;
inline long long in(){
	long long x=0,f=1;
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
long long a[300001],b[300001];
long long gy(long long x,long long y){
	long long z;
	while(y!=0){
		z=x%y;x=y;y=z;
	}
	return x;
}
int main(){
	long long n=in(),m=in(),i; 
	for(i=0;i<n;i++)a[i]=in();
	for(i=0;i<m;i++)b[i]=in();
	sort(a,a+n);
	if(n==1){
		cout<<"YES"<<endl<<a[0]<<" "<<1;return 0;
	}
	long long t=a[1]-a[0];
	for(i=1;i<n-1;i++){
		t=gy(t,a[i+1]-a[i]);
	}
	for(i=0;i<m;i++){
		if(t%b[i]==0){
			cout<<"YES"<<endl;
			cout<<a[0]<<" "<<i+1;return 0;
		}
	}
	cout<<"NO";
	return 0;
}