#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int s=0;
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();
	return s;
} 
int T,n;
int s,x,z,y;
int main()
{
	T=read();
	while(T--){
		n=read();
		s=read();
		y=read();
		x=read();
		z=read();
		bool flag=0;
		int zs,ys,zx,yx;
		for(int i=0;i<=1;i++){
			zs=i;
			for(int k=0;k<=1;k++){
				ys=k;
				for(int j=0;j<=1;j++){
					zx=j;
					for(int l=0;l<=1;l++){
						yx=l;
						if(zs+ys>s)continue;
						if(zx+yx>x)continue;
						if(zs+zx>z)continue;
						if(ys+yx>y)continue; 
						if(n-2+zs+ys>=s and n-2+zx+zs>=z and n-2+ys+yx>=y and n-2+zx+yx>=x)flag=1;
					}
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}