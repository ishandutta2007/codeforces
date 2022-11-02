#include<bits/stdc++.h> 
using namespace std;
int n,b;
double now,ans[1010]; 
int main(){
	scanf("%d%d",&n,&b);
	ans[n]=1.0*b;
	for (int i=n;i>1;i--){
		ans[i-1]=ans[i]*sqrt(1.0*(i-1)/i);
	}
	for(int i=1;i<n;i++) printf("%.10f ",ans[i]);
}