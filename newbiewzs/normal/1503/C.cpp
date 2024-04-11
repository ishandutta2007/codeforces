#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+55;
struct node{
	int a,c;
}a[N];
int cmp(node x,node y){
	return x.a<y.a;
} 
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].c;
	}
	int maxx=a[1].a+a[1].c;
	for(int i=2;i<=n;i++){
		ans+=max(0ll,a[i].a-maxx);
		maxx=max(a[i].a+a[i].c,maxx);
	}
	cout<<ans;
	return 0;
}