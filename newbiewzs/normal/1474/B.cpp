#include<bits/stdc++.h>
using namespace std;
const int N=1e5+55;
int T,n;
bool pd[N*5];
int st[N*5];
int cd[N*5],top;
void init(){
	for(int i=2;i<=N*5-5;i++){
		if(!pd[i])st[i]=i,cd[++top]=i;
		for(int k=1;k<=top and cd[k]*i<=N*5-5;k++){
			pd[cd[k]*i]=1;
		}
	}
} 
int main(){
	init();
	for(int i=N*5-5;i>=0;i--){
		if(!st[i])st[i]=st[i+1];
	}
	cin>>T;
	while(T--){
		cin>>n;
		int g=st[n+1]*st[st[n+1]+n];
		cout<<g<<endl;
	}
	return 0;
}