#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;

int n;
int a[5001];
int b[5001];
bool v[5001];
int Ans[5001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n){
		if(a[i]==0) continue;
		F(j,1,i){
			if(a[j]==0) continue;
			if((ll)a[i]*a[j]<0) continue;
			ll k=round(sqrt((ll)a[i]*a[j]));
			if(k*k==(ll)a[i]*a[j]){
				b[i]=j;
				break;
			}
		}
	}
	F(i,1,n){
		int k=0,z=1;
		F(j,i,n){
			if(a[j]==0) z=0;
			else{
				if(v[b[j]]==0) ++k;
				v[b[j]]=1;
			}
			++Ans[(z||k)?k:1];
		}
		F(j,i,n) v[b[j]]=0;
	}
	F(i,1,n) printf("%d ",Ans[i]);
	return 0;
}