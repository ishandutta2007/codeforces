#include<bits/stdc++.h>
using namespace std;
int n,m;
int y,z;
int f[1003],i,j;
bool x;
int main() {
	cin>>m>>n;
	int q=0,t1[1003],t2[1003];
	for(i=0; i<n; i++) {
		cin>>x>>y>>z;
		if(x) {
			for(j=y+1; j<=z; j++)f[j]=1;
		}else{
			t1[q]=y;t2[q]=z;
			q++;
		}
	}
	for(i=0;i<q;i++){
		bool pd=0;
		for(j=t1[i]+1;j<=t2[i];j++){
			if(!f[j]){
				pd=1;
			}
		}
		if(!pd){
			cout<<"NO";return 0;
		}
	}
	cout<<"YES"<<endl;
	int l=1,last=1;
	for(i=1; i<=m; i++) {
		if(!f[i]) {
			l=last-1;
			last=l;
		} else {
			l=last;
		}
		cout<<l+3000<<" ";
	}
	return 0;
}