#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int fx[2][2]={0,1,0,-1};
int h,l,f;char ans[105][105];
int p[105][105];
int x[55],a,b,c,d,n;
void next(){
	int t1=h,t2=l;
	h+=fx[f][0];l+=fx[f][1];
	if(!p[h][l]){
		h=t1;l=t2;
		h++;
		f=1-f;
	}
}
int main(){
	cin>>a>>b>>c>>d>>n;swap(a,b);swap(c,d);
	FOR(i,1,n)cin>>x[i];
	int t=a+b+c+d;
	FOR(i,1,a){
		FOR(j,1,b)p[i][j]=1;
	}
	FOR(i,1,c){
		FOR(j,b+1,d+b)p[i][j]=1;
	}
	if((min(a,c)&1)&&c>=a||(min(a,c)&1)==0&&c<=a){
		h=l=1;f=0;
	}else {
		h=1;l=b+d;
		f=1;
	}
	FOR(i,1,max(a,c)){
		FOR(j,1,b+d)ans[i][j]='.';
	}
	FOR(i,1,n){
		FOR(j,1,x[i]){
			ans[h][l]='a'+i-1;
			next();
		}
	}
	puts("YES");
	FOR(i,1,max(a,c)){
		FOR(j,1,b+d)cout<<ans[i][j];
		cout<<'\n';
	}
	return 0;
}