#include<bits/stdc++.h>
using namespace std;
int a[200005],l[200005],r[200005],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l1=1,q=0,ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1]){
			l[++q]=l1;
			r[q]=i-1;
			ans=max(ans,i-l1);
			l1=i;
		}
	}
	l[++q]=l1;
	r[q]=n;
	ans=max(ans,n-l1+1);
	for(int i=1;i<q;i++){
		if(r[i]>l[i]){
			if(a[r[i]-1]<a[l[i+1]]){
				ans=max(ans,r[i+1]-l[i]);
			}
		}
		if(r[i+1]>l[i+1]){
			if(a[r[i]]<a[l[i+1]+1]){
				ans=max(ans,r[i+1]-l[i]);
			}
		}
	}
	for(int i=1;i<=q-2;i++){
		if(a[r[i]]<a[l[i+2]]&&l[i+2]-r[i]==2){
			ans=max(ans,r[i+2]-l[i]-r[i+1]+l[i+1]);
		}
	}
	cout<<ans;
	return 0;
}