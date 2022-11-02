#include <bits/stdc++.h>
using namespace std;
map<int ,bool> m;
int a[200005],ans[200005],q;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(m[a[i]]==0){
			++q;
			if(q>k){
				m[ans[q-k]]=0;
			}
			ans[q]=a[i];m[a[i]]=1;
		}
	}
	cout<<min(q,k)<<'\n';
	for(int i=q;i>=max(q-k+1,1);i--){
		printf("%d ",ans[i]);
	}
	return 0;
}