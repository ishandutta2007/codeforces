#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
const int N=200010;
int n,m[N],s[N],S; long long ans;
int main(){
	scanf("%d",&n);
	ref(i,1,n){
		scanf("%d",&m[i]);
		ref(j,1,m[i]){
			int x;scanf("%d",&x);
			s[i]=max(s[i],x);
		}
		if(s[i]>S)S=s[i];
	}
	ref(i,1,n)ans+=1LL*(S-s[i])*m[i];
	cout<<ans<<endl;
}