#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[205],n,k;
bool cmp(int a,int b){return a>b;}
int cal(int x,int y)
{
 	int cnt=0;
 	for(int i=x;i<=y;i++)cnt+=a[i];
 	vector<int> in,out;
 	for(int i=0;i<x;i++)out.push_back(a[i]);
 	for(int i=x;i<=y;i++)in.push_back(a[i]);
	for(int i=y+1;i<n;i++)out.push_back(a[i]);
	sort(out.begin(),out.end(),cmp);
	sort(in.begin(),in.end());
	for(int i=0;i<out.size()&&i<in.size()&&i<k&&out[i]>in[i];i++)
	cnt=cnt+out[i]-in[i];
	return cnt;
}
int main()
{
 	cin>>n>>k;
 	for(int i=0;i<n;i++)cin>>a[i];
 	int ans=a[0];
 	for(int i=0;i<n;i++)for(int j=i;j<n;j++)ans=max(ans,cal(i,j));
 	cout<<ans<<endl;
 	//ystem("pause");
 	return 0;
}