#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n;
char s[100005];

int main(){
	cin>>(s+1);
	n=strlen(s+1);
	int x;
	for(x=1;x<=n;x++)
		if(s[x]=='2')
			break;
	int cnt=0,num=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
			cnt++;
	if(x>n){
		for(int i=1;i<=n-cnt;i++)
			cout<<'0';
		for(int i=1;i<=cnt;i++)
			cout<<'1';
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=x;i++)
		if(s[i]=='0')
			num++;
	for(int i=1;i<=num;i++)
		cout<<'0';
	for(int i=1;i<=cnt;i++)
		cout<<'1';
	cout<<'2';
	for(int i=x+1;i<=n;i++){
		if(s[i]=='1')
			continue;
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}