#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,m;
int a[maxn],s[maxn];
long long a1=0,a2=0;

int main(){
	scanf("%d",&n);
	s[0]=1;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i]<0){
			s[i]=-s[i-1];
		}
		else{
			s[i]=s[i-1];
		}
	}
	int ans=0;
	for (int i=1;i<=n;++i){
		if (s[i]<0) ans++;
	}
	long long t1=a1=ans,t2=a2=n-ans;
	for (int i=2;i<=n;++i){
		if (a[i-1]<0){
			t1--;
			swap(t1,t2);
			a1+=t1,a2+=t2; 
		}
		else{
			t2--;
			a1+=t1,a2+=t2;
		}
	}
	cout<<a1<<" "<<a2<<endl;
	return 0;
}