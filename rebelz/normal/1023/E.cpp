#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int n;
char s[10],ans1[100005],ans2[100005];

int main(){
	cin>>n;
	int nowx=n,nowy=n;
	for(int i=1;i<=n-1;i++){
		cout<<"? 1 1 "<<nowx-1<<' '<<nowy<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='Y'){
			nowx--;
			ans2[i]='D';
		}
		else{
			nowy--;
			ans2[i]='R';
		}
	}
	nowx=1,nowy=1;
	for(int i=1;i<=n-1;i++){
		cout<<"? "<<nowx<<' '<<nowy+1<<' '<<n<<' '<<n<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='Y'){
			nowy++;
			ans1[i]='R';
		}
		else{
			nowx++;
			ans1[i]='D';
		}
	}
	cout<<"! ";
	for(int i=1;i<=n-1;i++)
		cout<<ans1[i];
	for(int i=n-1;i>=1;i--)
		cout<<ans2[i];
	cout<<endl;
	return 0;
}