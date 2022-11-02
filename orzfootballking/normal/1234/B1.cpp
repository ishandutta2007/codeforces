#include <bits/stdc++.h>
using namespace std;
int a[200005],ans[200005],q;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int f=1;
		for(int j=q;j>=max(q-k+1,1);j--){
			if(ans[j]==a[i]){
				f=0;break;
			}
		}
		if(f){
			ans[++q]=a[i];
		}
	}
	cout<<min(q,k)<<'\n';
	for(int i=q;i>=max(q-k+1,1);i--){
		printf("%d ",ans[i]);
	}
	return 0;
}