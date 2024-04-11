#include <bits/stdc++.h>
using namespace std;
inline void write(int X)
{
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) write(X/10);
	putchar(X%10+'0');
}
void dfs(int n,int p){
	if(n==1){
		write(p);putchar(' ');return;
	}
	int t=-1,maxi=0;
	for(int i=2;i<=n;i++){
		if(n/i>=maxi){
			maxi=n/i;t=i;
		}
	}
	for(int i=0;i<n-maxi;i++)write(p),putchar(' ');
	dfs(maxi,p*t);
}
int main(){
	int n;
	cin>>n;
	dfs(n,1);
	return 0;
}