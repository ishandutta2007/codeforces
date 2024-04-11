#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define PB push_back
using namespace std;

int n,a[2005],b[2005];

int main(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d",&a[i]);
	For(i,1,2*n) b[i]=a[i];
	
	int s1=-1,s2=-1;
	For(i,1,2*n){
		bool flg=1;
		For(j,1,n*2) flg&=(a[j]==j);
		if (flg){
			s1=i-1;
			break;
		}
		if (i&1){
			For(j,1,n) swap(a[j],a[j+n]);
		}
		else{
			For(j,1,n) swap(a[2*j],a[2*j-1]);
		}
	}
	
	For(i,1,2*n) a[i]=b[i];
	For(i,1,2*n){
		bool flg=1;
		For(j,1,n*2) flg&=(a[j]==j);
		if (flg){
			s2=i-1;
			break;
		}
		if (!(i&1)){
			For(j,1,n) swap(a[j],a[j+n]);
		}
		else{
			For(j,1,n) swap(a[2*j],a[2*j-1]);
		}
	}
	
	if (s1==-1) cout<<s2<<endl;
	else if (s2==-1) cout<<s1<<endl;
	else cout<<min(s1,s2)<<endl;
}