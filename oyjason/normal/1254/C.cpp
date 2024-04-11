#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
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
#define M 10200
int n;
int p[M];
int od[M];
int m;
int l[M],ls;
int r[M],rs;
LL S[M];
inline bool cmp(int x,int y){return S[x]<S[y];}
int main(){
	cin>>n;
	int nxt=2;
	for(int i=3;i<=n;i++){
		cout<<"2 1 "<<nxt<<" "<<i<<endl; fflush(stdout);
		int w; cin>>w; if(w==-1) nxt=i;
	}
	for(int i=2;i<=n;i++) if(i!=nxt){
		od[++m]=i;
		cout<<"1 1 "<<nxt<<" "<<i<<endl; fflush(stdout);
		cin>>S[i];
	} sort(od+1,od+m+1,cmp);
	for(int i=1;i<m;i++){
		cout<<"2 1 "<<od[i]<<" "<<od[m]<<endl; fflush(stdout);
		int w; cin>>w; if(w==1) r[++rs]=od[i]; else l[++ls]=od[i];
	}
	cout<<"0 1 "<<nxt;
	for(int i=1;i<=rs;i++) cout<<" "<<r[i];
	cout<<" "<<od[m];
	for(int i=ls;i>=1;i--) cout<<" "<<l[i];
	cout<<endl;
	fflush(stdout);
	return 0;
}