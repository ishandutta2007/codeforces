#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int p[1000005];
int main(){
	p[0]=1;
	for (int i=1;i<1000005;i++) p[i]=p[i-1]*2%mod;
	int a,b;
	cin>>a>>b;
	if (a==1){
		cout<<p[b+1]<<endl;
		return 0;
	}
	if (b==1){
		cout<<p[a+1]<<endl;return 0;
	}
	cout<<p[a+b]<<endl;
	return 0;
}