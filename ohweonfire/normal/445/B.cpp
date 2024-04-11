#include <iostream>
using namespace std;
int f[102],n,m,x,y;
int main(){
	cin>>n>>m;
	long long ans=1;
	for(int i=0;i<=n;i++)f[i]=i;
	while(m--){
			   cin>>x>>y;
			   while(f[x]!=x)x=f[x];
			   while(f[y]!=y)y=f[y];
			   if(x!=y)ans*=2;
			   f[y]=x;
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}