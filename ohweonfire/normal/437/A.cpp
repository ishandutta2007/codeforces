#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5],v[5];
bool g[5];
int main(){
	int n=4;
	for(int i=0;i<n;i++){string s;cin>>s;a[i]=v[i]=s.size()-2;}
	sort(v,v+n);
	if(v[0]*2<=v[1])for(int i=0;i<n;i++)if(a[i]==v[0])g[i]=true;
	if(v[2]*2<=v[3])for(int i=0;i<n;i++)if(a[i]==v[3])g[i]=true;
	if(g[0]+g[1]+g[2]+g[3]==1){for(int i=0;i<n;i++)if(g[i]==1 )cout<<char('A'+i)<<endl;}
	else cout<<"C\n";
	//system("pause");
	return 0;
}