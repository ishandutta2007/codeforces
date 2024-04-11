#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int s=0;
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();
	return s;
} 
const int N=55;
int T,n;
char s[N];
int main()
{
	T=read();
	while(T--){
		bool flag=0;
		scanf("%s",s+1);
		for(int i=1;i<=2;i++){
			for(int k=1;k<=2;k++){
				for(int j=1;j<=2;j++){
					int aa=0;
					int l=strlen(s+1);
					bool zs=0;
					for(int h=1;h<=l;h++){
						if(s[h]=='A'){
							if(i==1){
							 	if(aa<0){
							 		zs=1;
								 }
								 aa++;
							 }
							 else if(i==2){
								 aa--;
								 if(aa<0){
								 	zs=1;
								 }
							 }
						}
						if(s[h]=='B'){
							if(k==1){
							 	if(aa<0){
							 		zs=1;
								 }
								 aa++;
							 }
							 else if(k==2){
								 aa--;
								 if(aa<0){
								 	zs=1;
								 }
							 }
						}
						if(s[h]=='C'){
							if(j==1){
								if(aa<0){
									zs=1;
									 }
									 aa++;
								 }
								 else if(j==2){
									 aa--;
									 if(aa<0){
									 	zs=1;
									 }
								 }
						} 
					}
					if(!zs and !aa){
						flag=1;
					}
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}