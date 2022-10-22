#include <bits/stdc++.h>
using namespace std;
int x[100005],y[100005],l[100005];
int r[20][105][105];
int main(){
	int n,q,c;
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>l[i];
	for(int i=0;i<=c;i++){
		for(int j=1;j<=n;j++){
			r[i][x[j]][y[j]]+=l[j];
		}
		for(int j=1;j<=100;j++){
			for(int k=2;k<=100;k++){
				r[i][j][k]+=r[i][j][k-1];
			}
		}
		for(int j=2;j<=100;j++){
			for(int k=1;k<=100;k++){
				r[i][j][k]+=r[i][j-1][k];
			}
		}
		for(int j=1;j<=n;j++){
			l[j]=(l[j]+1)%(c+1);
		}
	}
	int t1,t2,t3,t4,t5;
	for(int j=0;j<q;j++){
		cin>>t1>>t2>>t3>>t4>>t5;
		cout<<r[t1%(c+1)][t4][t5]-
		r[t1%(c+1)][t4][t3-1]-r[t1%(c+1)][t2-1][t5]
		+r[t1%(c+1)][t2-1][t3-1]<<'\n';
	}
	return 0;
}