#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=105;
int T,n,k;
int main(){
	cin>>T;
	while(T--){
		n=read();k=read();
		if(n%2==0){
			if(k%n)cout<<(k%n)<<endl;
			else cout<<n<<endl;
		}
		else{
			k--;
			k+=k/(n/2);
			k++;
			if(k%n)cout<<(k%n)<<endl;
			else cout<<n<<endl;
		}
	}
	return 0;
}