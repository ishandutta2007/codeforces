#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std; 
const int N=4e5+9;
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b){
		if(a==b+1&&!c&&!d){
			printf("YES\n");
			printf("0 ");
			rep(i,0,b)printf("%d %d ",1,0);
			return 0;
		}
		printf("NO");
		return 0;
	}
	if(d>c){
		if(d==c+1&&!a&&!b){
			printf("YES\n");
			printf("3 ");
			rep(i,0,c)printf("%d %d ",2,3);
			return 0;
		}
		printf("NO");
		return 0;
	}
	if(a+c==b+d){
		printf("YES\n");
		rep(i,0,a)printf("%d %d ",0,1);
		b-=a;
		rep(i,0,b)printf("%d %d ",2,1);
		c-=b;
		rep(i,0,c)printf("%d %d ",2,3);
		return 0;
	}
	if(a+c==b+d+1){
		printf("YES\n");
		rep(i,0,a)printf("%d %d ",0,1);
		b-=a;
		rep(i,0,b)printf("%d %d ",2,1);
		c-=b;
		rep(i,0,d)printf("%d %d ",2,3);
		printf("%d",2);
		return 0;
	}
	if(a+c+1==b+d){
		printf("YES\n");
		printf("%d ",1);
		b--;
		rep(i,0,a)printf("%d %d ",0,1);
		b-=a;
		rep(i,0,b)printf("%d %d ",2,1);
		c-=b;
		rep(i,0,c)printf("%d %d ",2,3);
		return 0;
	}
	printf("NO");
}