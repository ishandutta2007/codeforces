#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int n, a[3];
int d[310][310];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    int ans=0;
    if (n==1) ans=a[0];
    if (n==2) {
	ans=1;
	if (a[0]>a[1]) swap(a[0], a[1]);
	for (int i=0; i<310; i++) {
	    for (int j=0; j<310; j++) {
		if (d[i][j]==0) {
		    for (int k=1; k+i<310; k++) d[k+i][j]=1;
		    for (int k=1; k+j<310; k++) d[i][k+j]=1;
		    for (int k=1; k+i<310 && k+j<310; k++) d[k+i][k+j]=1;
		}
	    }
	}
	ans=d[a[0]][a[1]];
    }
    if (n==3) {
	ans=a[0]^a[1]^a[2];
    }
    puts(ans?"BitLGM":"BitAryo");
    return 0;
}