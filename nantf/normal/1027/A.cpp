#include<bits/stdc++.h>
using namespace std;
int t,n;
char str[101];
bool flag;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,str+1);
		flag=true;
		for(int i=1,j=n;i<j;i++,j--)
			if(abs(str[i]-str[j])!=0 && abs(str[i]-str[j])!=2){
				printf("NO\n");flag=false;break;
			}
		if(flag) printf("YES\n");
	}
}