#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

char s[105];

int main(){
	cin>>(s+1);
	int n=strlen(s+1);
	if(s[n]!='a'&&s[n]!='e'&&s[n]!='i'&&s[n]!='o'&&s[n]!='u'&&s[n]!='n'){
		cout<<"NO"<<endl;
		return 0;
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(flag&&s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'){
			cout<<"NO"<<endl;
			return 0;
		}
		else if(flag)
			flag=false;
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='n')
			flag=true;
	}
	cout<<"YES"<<endl;
	return 0;
}