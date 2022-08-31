#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n;
bool vis[1005];

int getans(int x){
	int ans=0;
	for(int i=0;i<=x;i++)
		for(int j=0;i+j<=x;j++)
			for(int k=0;i+j+k<=x;k++)
				if(!vis[i*49+j*9+k*4+x])
					vis[i*49+j*9+k*4+x]=true,ans++;
	return ans;
}

int main(){
	cin>>n;
	if(n<=15)
		cout<<getans(n)<<endl;
	else
		cout<<getans(15)+(n-15)*49<<endl;
	return 0;
}