#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

char s[50005],ans[50005];
int n,p,cnt;

int main(){
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		ans[i]=s[i];
	for(int i=1;i<=n/2;i++){
		p=i,cnt=0;
		for(int j=i+1;j<=n;j++){
			if(s[j]==s[j-i])
				cnt++;
			else
				cnt=0;
			if(cnt==i){
				p-=cnt;
				cnt=0;
			}
			s[++p]=s[j];
		}
		n=p;
	}
	for(int i=1;i<=n;i++)
		cout<<s[i];
	cout<<endl;
	return 0;
}