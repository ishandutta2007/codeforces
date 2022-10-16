#include <iostream>
using namespace std;
int n, a[500+25], mmax, pmax, win[500+25];
long long k;
int main(){
	cin>>n>>k;
	cin>>a[1];
	mmax=a[1];
	pmax=1;
	for(int i=2; i<=n; i++){
		cin>>a[i];
		if(a[i]>mmax){
			pmax=i;
			mmax=a[i];
		}
	}
	if(k+1>=pmax){
		cout<<mmax<<endl;
		return 0;
	}
	while(1){
		int cnt=0;
		bool flag=true;
		while(cnt+win[1]<k){
			if(a[1]>a[2]){
				cnt++;
				int tmp=a[2];
				for(int j=3; j<=n; j++)
					a[j-1]=a[j], win[j-1]=win[j];
				a[n]=tmp, win[n]=0;
				continue;
			}
			int tmp=a[1];
			for(int j=2; j<=n; j++)
				a[j-1]=a[j], win[j-1]=win[j];
			a[n]=tmp, win[n]=0;
			win[1]++;
			flag=false;
			break;
		}
		if(flag){
			cout<<a[1]<<endl;
			return 0;
		}
	}
}