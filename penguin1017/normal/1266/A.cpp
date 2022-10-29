#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
char s[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s); 
		int tot=0,sum=0,flag=0;
		int len=strlen(s);
		rep(i,0,len){
			if(s[i]=='0'){
				++tot;
			}
			else{
				sum+=s[i]-48;
				if(s[i]%2==0)flag=1;
			}
		}
		if(sum%3){
			printf("cyan\n");
			continue;
		}
		if(!tot){
			printf("cyan\n");
			continue;
		}
		if(tot==1&&flag==0){
			printf("cyan\n");
			continue;
		}
		printf("red\n");
		
	}
}