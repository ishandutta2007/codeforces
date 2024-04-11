#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,a[200005],b[200005],top,head;
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		top=head=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			if(x%2==0)a[++top]=x;
			else b[++head]=x;
		}
		sort(a+1,a+top+1);
		sort(b+1,b+head+1);
		int ans1=0,ans2=0;
		int cn=0;
		while(top and head){
			cn++;
			if(cn%2==1){
				if(a[top]>b[head]){ans1+=a[top];top--;}
				else{head--;}
			}
			else{
				if(b[head]>a[top]){ans2+=b[head];head--;}
				else{top--;}
			}
		}
		while(top){
			cn++;
			if(cn%2==1){
				ans1+=a[top];
				top--;
			}
			else{
				top--;
			}
		}
		while(head){
			cn++;
			if(cn%2==1){
				head--;
			}
			else{
				ans2+=b[head];
				head--;
			}
		}
		if(ans1>ans2)puts("Alice");
		if(ans1==ans2)puts("Tie");
		if(ans1<ans2)puts("Bob");
	}
	return 0;
}