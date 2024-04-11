#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 2200020
int n;
int a[M],p[M];
char ch[M];
int main(){
	n=read();
	scanf("%s",ch+1);
	int cnt=0,ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(ch[i]=='(') sum++;
		else sum--;
		if(sum<0) cnt=1;
		ans+=cnt;
		cnt=(sum<0);
	}
	if(sum!=0) ans=-1;
	printf("%d\n",ans);
	return 0;
}