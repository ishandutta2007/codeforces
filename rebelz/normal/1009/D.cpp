#include<iostream>
#include<string.h>

using namespace std;

typedef long long ll;

int n,m,tot=0;
bool flag[1000005];
ll prime[1000005],phi[1000005];

int gcd(int x,int y){
	if(y==0)
		return x;
	return gcd(y,x%y);
}

void getprime(){
	memset(flag,true,sizeof(flag));
	flag[1]=false,phi[1]=1;
	for(int i=2;i<=n;i++){
		if(flag[i]){
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			flag[i*prime[j]]=false;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}

int main(){
	cin>>n>>m;
	getprime();
	ll s=0;
	for(int i=2;i<=n;i++)
		s+=phi[i];
	if(s<m||m<n-1){
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<"Possible"<<endl;
	int cnt=n-1;
	for(int i=2;i<=n;i++)
		cout<<1<<' '<<i<<endl;
	if(cnt==m)
		return 0;
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			if(gcd(i,j)==1){
				cout<<i<<' '<<j<<endl;
				cnt++;
				if(cnt==m)
					return 0;
			}
		}
	}
	return 0;
}