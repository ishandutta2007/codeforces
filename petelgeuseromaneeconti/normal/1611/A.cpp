#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=20;
int T;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(s[n]%2==0){
			puts("0");
		}else{
			if(s[1]%2==0){
				puts("1");
			}else{
				bool flg=0;
				rep(i,1,n){
					if(s[i]%2==0){
						flg=1;
						break;
					}
				}
				if(flg){
					puts("2");
				}else{
					puts("-1");
				}
			}
		}
	}
	return 0;
}