#include<bits/stdc++.h>
using namespace std;
int T;
const int N=10005;
int a[N],n,m,st[N],top;
int f[N];
int main(){
	cin>>T;
	/*f[7]=f[17]=f[27]=f[37]=f[47]=f[71]=f[72]=f[73]=f[74]=f[75]=f[76]=f[77]=f[78]=f[79]=f[57]=f[67]=f[77]=f[87]=f[97]=1;
	for(int i=1;i<=100;i++){
		for(int k=1;k<=100;k++){
			if(i+k==51 and f[i] and f[k]){
				new char;
			}
			f[i+k]|=(f[i]&f[k]);
		}
	}*/
//	for(int i=1;i<=100;i++){
//		cout<<i<<" "<<f[i]<<endl;
//	}
//	return 0;
	while(T--){
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof(f));
		for(int i=1;i<=100;i++){
			int u=i;
			bool flag=0;
			while(u){
				if(u%10==m)flag=1;
				u/=10;
			}
			if(flag)f[i]=1;
		}
		for(int i=1;i<=100;i++){
			for(int k=1;k<=i;k++){
				f[i]|=(f[i-k]&f[k]);
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<=100){
				if(f[a[i]])puts("YES");
				else puts("NO");
			}
			else{
				puts("YES"); 
			}
		}
	}
	return 0;
}