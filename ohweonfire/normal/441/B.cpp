#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=3002;
int a[maxn],b[maxn],n,v;
int main(){
	cin >> n >> v;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[i]>a[j]){swap(a[i],a[j]),swap(b[i],b[j]);}
	int ans=0;
	for(int i=1;i<=3002;i++){
			int sum=0;
			for(int j=0;j<n;j++)
					if(a[j]==i||a[j]==i-1){
										   sum+=b[j];
										   b[j]=0;
										   if(sum>v){
										   			 b[j]=sum-v;
										   			 sum=v;
										   			 break;
										}
					}
			ans+=sum;
	}
	
	cout<<ans<<endl;
	//system("pause");
	return 0;
}