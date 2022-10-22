#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id,zhi;
}a[200005];
bool cmp(node x,node y){
	return x.zhi<y.zhi;
}
bool check(int x){
	int b[200005],q=1;
	for(int i=1;i<=n;i++){
		if(i!=x)b[q++]=a[i].zhi;
	}
	int s=b[2]-b[1];
	for(int i=3;i<n;i++){
		if(b[i]-b[i-1]!=s)return 0;
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].zhi,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	if(n==2||n==3){
		cout<<1;return 0;
	}
	int f=2,s;
	if(check(1)){
		cout<<a[1].id;return 0;
	}
	if(check(2)){
		cout<<a[2].id;return 0;
	}
	if(check(n)){
		cout<<a[n].id;return 0;
	}
	s=a[2].zhi-a[1].zhi;
	int ans;
	for(int i=3;i<=n;i++){
		if(a[i].zhi-a[i-1].zhi!=s){
			if(a[i+1].zhi-a[i-1].zhi!=s||f==1){
				cout<<-1;return 0;
			}else f--,ans=a[i].id,i++;
		}
	}
	cout<<ans;
	return 0;
}