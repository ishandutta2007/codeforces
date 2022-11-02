#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=105;
int T,n;
int bj[N][3];
int tong[N];
int main(){
	cin>>T;
	while(T--){
		n=read();
		if(n&1){
			for(int i=1;i<=n;i++){
				for(int k=i+1;k<=n;k++){
					if(k-i<=(n/2))cout<<"1 ";
					else cout<<"-1 ";
				}
			}
			puts("");
		}
		else{
			memset(bj,0,sizeof(bj));
			int xz=n/2-1;
			for(int i=1;i<=n;i++){
				for(int k=i+1;k<=n;k++){
					if(!bj[i][0]){
						cout<<"0 ";
						tong[i]++;tong[k]++;
						bj[i][0]=bj[k][0]=1; 
					}
					else if(bj[i][1]<xz and bj[k][2]<xz){
						cout<<"1 ";
						tong[i]+=3;
						bj[i][1]++;bj[k][2]++; 
					}
					else{
						cout<<"-1 ";
						tong[k]+=3;
						bj[i][2]++;bj[k][1]++; 
					}
				}
			}
		//	for(int i=2;i<=n;i++)if(tong[i]!=tong[i-1])puts("?");
			puts("");
		}
	}
	return 0;
}