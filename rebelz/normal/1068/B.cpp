#include<bits/stdc++.h>

using namespace std;

long long b;
bool flag[2000005];

void getprime(int n){
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	for(int i=2;i<=n;i++)
		for(int j=i+i;j+i<=n;j+=i)
			flag[j]=false;
}

int main(){
	getprime(1000000);
	cin>>b;
	int ans=1;
	for(int i=2;i<=sqrt(b);i++){
		int cnt=0;
		if(flag[i]&&b%i==0){
			while(b%i==0){
				b/=i,cnt++;
			}
		}
		ans*=(cnt+1);
	}
	if(b!=1)
		ans*=2;
	cout<<ans<<endl;
	return 0;
}