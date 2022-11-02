#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s; 
}
const int N=51;
int T;
char a[N]; 
int main(){
	T=read();
	while(T--){
		scanf("%s",a+1);
		int n=strlen(a+1);
		for(int i=1;i<=n;i++){
			if(i%2==1){
				if(a[i]=='a'){
					a[i]='b';
				}
				else{
					a[i]='a';
				}
			}
			else{
				if(a[i]=='z'){
					a[i]='y';
				}
				else{
					a[i]='z';
				}
			}
			cout<<a[i];
		}
		puts("");
	} 
	return 0;
}