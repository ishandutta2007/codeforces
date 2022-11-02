#include<bits/stdc++.h>
using namespace std;
int n,a[2020],b[2020],f1,f2;
int check1(){
	for (int i=0;i<2*n;i++)
	if (a[i]!=b[i]) return 0;
	return 1;
}
int check2(){
	for (int i=0;i<2*n;i++)
	if (b[i]!=i+1) return 0;
	return 1;
}
void printb(){
	for (int i=0;i<2*n;i++) printf("%d ",b[i]);
	printf("\n");
}
void dfs(int x){
	for (int i=0;i<n;i++){
		if (x==0) swap(b[2*i],b[2*i+1]);
		else swap(b[i],b[i+n]);
	}
	//printb();
	f2++;
	if (check1()) f1=f2;
	if (!check2()) dfs(x^1);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<2*n;i++) scanf("%d",&a[i]);
	for (int i=0;i<2*n;i++) b[i]=i+1;
	f1=-1;
	dfs(0);
	printf("%d\n",min(f1,f2-f1));
}