#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int x;
string str;
int main(){
	while(true){
		printf("next 0\nnext 0 1\n");
		fflush(stdout);
		cin>>x;
		ROF(i,x,1) cin>>str;
		cin>>x;
		ROF(i,x,1) cin>>str;
		if(x==2) break;
	}
	while(true){
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		cin>>x;
		ROF(i,x,1) cin>>str;
		if(x==1) break;
	}
	puts("done");
	fflush(stdout);
}
//CDWDDW