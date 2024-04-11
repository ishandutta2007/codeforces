#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,k;
char s[200005];

int main(){
	cin>>n>>k>>(s+1);
	int nowcnt=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('&&cnt<k/2){
			cout<<s[i];
			cnt++,nowcnt++;
		}
		else if(s[i]==')'&&nowcnt>0){
			nowcnt--;
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}