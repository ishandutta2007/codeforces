#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		int i,j;
		int b[1111];
		for(i=0;i<2*a;i++)
		cin>>b[i];
		int c[1111];
		for(i=0;i<a*2;i++)
		c[i]=b[i];
		int a1=0;
		int sum=0;
		int ans=99999999;
		int s,ss;
		for(i=0;i<=a*2-1;i++){
			for(j=2*a-1;j>i;j--){
				if(i==j)continue;
				for(int ts=0;ts<=2*a-1;ts++)
				b[ts]=c[ts];
				s=b[i];
				ss=b[j];
				b[i]=1111111;
				b[j]=1111111;
				sort(b,b+a*2);
				int ans1=0;
				for(int k=1;k<=2*a-1-2;k+=2)
				ans1+=b[k]-b[k-1];
				ans=min(ans1,ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}