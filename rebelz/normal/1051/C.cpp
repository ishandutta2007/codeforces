#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
int a[105],cnt[105];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int num=0,val=0;
	for(int i=1;i<=100;i++){
		if(cnt[i]==1)
			num++;
		if(cnt[i]>=3)
			val++;
	}
	if(num%2==1&&val==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	int now=num/2;
	if(num%2==1){
		int tmp=1;
		for(int i=1;i<=n;i++){
			if(cnt[a[i]]==1&&now>0){
				now--;
				cout<<"A";
			}
			else if(cnt[a[i]]==1)
				cout<<"B";
			else if(cnt[a[i]]>=3&&tmp){
				tmp--;
				cout<<"A";
			}
			else
				cout<<"B";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]==1&&now>0){
			now--;
			cout<<"A";
		}
		else if(cnt[a[i]]==1)
			cout<<"B";
		else
			cout<<"A";
	}
	cout<<endl;
	return 0;
}