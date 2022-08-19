#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long ll;
const int cys=998244353;
int n,k;
ll d[1005][2005][2][2];

int main(){
	cin>>n>>k;
	d[1][1][0][0]=d[1][2][0][1]=d[1][2][1][0]=d[1][1][1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			for(int c1=0;c1<=1;c1++){
				for(int c2=0;c2<=1;c2++){
					if(c1==c2){
						d[i][j][c1][c2]=(d[i-1][j][c1][c2]+d[i-1][j][c1][!c2]+d[i-1][j][!c1][c2])%cys;
						if(j>1)
							d[i][j][c1][c2]=(d[i][j][c1][c2]+d[i-1][j-1][!c1][!c2])%cys;
					}
					else{
						d[i][j][c1][c2]=d[i-1][j][c1][c2];
						if(j>1)
							d[i][j][c1][c2]=(d[i][j][c1][c2]+d[i-1][j-1][c1][!c2]+d[i-1][j-1][!c1][c2])%cys;
						if(j>2)
							d[i][j][c1][c2]=(d[i][j][c1][c2]+d[i-1][j-2][!c1][!c2])%cys;
					}
				}
			}
		}
	}
	cout<<(d[n][k][0][0]+d[n][k][0][1]+d[n][k][1][0]+d[n][k][1][1])%cys<<endl;
	return 0;
}