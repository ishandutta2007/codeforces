#include<bits/stdc++.h>
using namespace std;
int k,n,tot,name[50];
string s;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<k-1;i++) name[i]=tot++;
	for (int i=0;i<n-k+1;i++){
		cin>>s;
		if (s=="YES") name[i+k-1]=tot++;
		else name[i+k-1]=name[i];
	}
	for (int i=0;i<n;i++){
		for (int j=max(0,i-k+1);j<i;j++){
		}
	}
	for (int i=0;i<n;i++){
		printf("%c%c ",'A'+name[i]/26,'a'+name[i]%26);
	}
}