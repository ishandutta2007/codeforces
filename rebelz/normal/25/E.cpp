#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef unsigned long long ll;
const ll base=29;
char s[5][100005];
int n[5],match[5][5],num;
ll h[5][100005],b[100005];

int main(){
	b[0]=1,num=3;
	for(int i=1;i<=100000;i++)
		b[i]=b[i-1]*base;
	cin>>s[1]+1>>s[2]+1>>s[3]+1;
	for(int i=1;i<=3;i++)
		n[i]=strlen(s[i]+1);
	for(int i=1;i<=3;i++)
		for(int j=i+1;j<=3;j++)
			if(n[i]>n[j])
				swap(s[i],s[j]),swap(n[i],n[j]);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n[i];j++)
			h[i][j]=h[i][j-1]*base+s[i][j]-'a';
	for(int i=1;i<=3;i++)
		for(int j=i+1;j<=3;j++)
			for(int k=1;k<=n[j]-n[i]+1;k++)
				if(h[i][n[i]]==h[j][k+n[i]-1]-h[j][k-1]*b[n[i]])
					n[i]=1<<30;
	for(int i=1;i<=3;i++)
		for(int j=i+1;j<=3;j++)
			if(n[i]>n[j])
				swap(n[i],n[j]),swap(s[i],s[j]),swap(h[i],h[j]);
	if(n[3]==(1<<30))
		num--;
	if(n[2]==(1<<30))
		num--;
	for(int i=1;i<=num;i++)
		for(int j=1;j<=num;j++)
			for(int k=1;k<=min(n[i],n[j]);k++)
				if(h[i][n[i]]-h[i][n[i]-k]*b[k]==h[j][k])
					match[i][j]=max(match[i][j],k);
	int ans=1<<30;
	if(num==3){
		for(int i=1;i<=num;i++)
			for(int j=1;j<=num;j++)
				for(int k=1;k<=num;k++)
					if(i!=j&&i!=k&&j!=k)
						ans=min(ans,n[1]+n[2]+n[3]-match[i][j]-match[j][k]);
	}
	else if(num==2){
		for(int i=1;i<=num;i++)
			for(int j=1;j<=num;j++)
				if(i!=j)
					ans=min(ans,n[1]+n[2]-match[i][j]);
	}
	else
		ans=n[1];
	cout<<ans<<endl;
	return 0;
}