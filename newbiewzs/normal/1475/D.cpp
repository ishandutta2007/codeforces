#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,s;
int a[255555],b[255555];
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
int c[255555],d[255555];
int topa,topb;
int cmp(int x,int y){
	return x>y;
}
signed main(){
	cin>>T;
	while(T--){
		n=read();m=read();topa=topb=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++){
			if(b[i]==1)c[++topa]=a[i];
			else d[++topb]=a[i];
		}
		sort(c+1,c+topa+1,cmp);
		sort(d+1,d+topb+1,cmp);
		for(int i=2;i<=topa;i++){
			c[i]=c[i-1]+c[i];
			
		}
		for(int i=2;i<=topb;i++){
			d[i]=d[i-1]+d[i];
		}
		
		int minn=1e15;
		for(int i=0;i<=topa;i++){
			if(c[i]>=m)minn=min(minn,i);
			else{
				int hh=lower_bound(d+1,d+topb+1,m-c[i])-d;
				if(d[hh]+c[i]>=m and hh<=topb)minn=min(minn,i+hh*2);
			}
		}
		for(int i=0;i<=topb;i++){
			if(d[i]>=m)minn=min(minn,2*i);
			else{
				int hh=lower_bound(c+1,c+topa+1,m-d[i])-c;
				if(d[i]+c[hh]>=m and hh<=topa)minn=min(minn,hh+i*2);
			} 
		}
		if(c[topa]+d[topb]<m){
			for(int i=1;i<=topa;i++)c[i]=0;
			for(int i=1;i<=topb;i++)d[i]=0;
			puts("-1");
			continue;
		} 
		for(int i=1;i<=topa;i++)c[i]=0;
		for(int i=1;i<=topb;i++)d[i]=0;
		
		printf("%lld\n",minn);
	}
	return 0;
} 
/*
6
5 7
5 3 2 1 4
2 1 1 2 1
1 3
2
1
5 10
2 3 2 3 2
1 2 1 2 1
4 10
5 1 3 4
1 2 1 2
4 5
3 2 1 2
2 1 2 1
4 5
5 2 2 1
2 1 1 1
*/