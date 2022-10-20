#include <bits/stdc++.h>//This is not my code! Just want to test it.
using namespace std;
int a[200005],n,m,k;
int nw,ncnt;
int main(){
	cin>>n>>m>>k;
	int i,j;
	for(i=1;i<=n;++i) cin>>a[i];
	nw=1,ncnt=0;
	for(i=n;i;--i){
		if(ncnt+a[i]>k){            //
			++nw;
			ncnt=a[i];
		}else ncnt+=a[i];
		if(nw==m+1) break;     //
	}
	cout<<n-i<<endl;
	return 0;
}