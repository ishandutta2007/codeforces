#include<bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001];
int main(){
	scanf("%s%s",a,b);
	int i;
	for(i=0;i<strlen(b);i++){
		if(a[i]!=b[i])break;
	}
	int j;
	for(j=strlen(a);j>0;j--){
		if(a[j]!=b[j-1])break;
	}
	j--;
	if(i>j){
		cout<<i-j<<endl;
	}else cout<<0;
	for(int k=j+1;k<=i;k++)cout<<k+1<<" ";
	return 0;
}