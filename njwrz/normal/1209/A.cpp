#include <bits/stdc++.h>
using namespace std;
int f[101],a[101];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	sort(a+1,a+n+1);
	int answer=0;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			answer++;
			for(int j=i;j<=n;j++)
				if(a[j]%a[i]==0)f[j]=1;
		}
	}
	cout<<answer;
	return 0;
}