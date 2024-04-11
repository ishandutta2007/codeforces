#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=40000;
int T,n;
int a[N];
bool pd[N];
vector<int>v[4];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int ling=0,yi=0,er=0;
		for(int i=1;i<=n;i++){
			if(a[i]%3==0){
				ling++;
			}
			if(a[i]%3==1){
				yi++;
			}
			if(a[i]%3==2){
				er++;
			}
		} 
		
		int ping=n/3;
		int ans=0;
		if(ling>ping)yi+=ling-ping,ans+=ling-ping,ling=ping;
		if(yi>ping)er+=yi-ping,ans+=yi-ping,yi=ping;
		if(er>ping)ling+=er-ping,ans+=er-ping,er=ping;
		if(ling>ping)yi+=ling-ping,ans+=ling-ping,ling=ping;
		if(yi>ping)er+=yi-ping,ans+=yi-ping,yi=ping;
		if(er>ping)ling+=er-ping,ans+=er-ping,er=ping;
		cout<<ans<<endl;
	}
	return 0;
}