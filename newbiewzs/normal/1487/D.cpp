#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=1e5;
int T,n,top;
int cd[N];
signed main(){
	for(int i=1;i<=1e9;i++){
		if((i*i)%2==1){
			int c=(i*i+1)/2;
			if(c>1e9){
				break;
			}
			int b=c-1;
			if(b<1)continue;
			if(c+b==i*i and i*i+b*b==c*c){
				cd[++top]=max(i,max(c,b));
			}
		}
	}
	cin>>T;
	while(T--){
		n=read();
		int hh=upper_bound(cd+1,cd+top+1,n)-cd-1;
		cout<<hh<<endl;
	}
	return 0;
}