#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

int k, t, p;
bool a[111][111];

int main(){
    scanf("%d", &k);
    t=0;
    for (p=2;;p++) {
	if (t+p*(p-1)/2>k) break;
	else t+=p*(p-1)/2;
    }
    for (int i=0; i<p; i++) {
	for (int j=i+1; j<p; j++) {
	    a[i][j]=a[j][i]=1;
	}
    }
    k-=t;
    int x=0;
    for (;k;) {
	int q=2;
	t=0;
	for (;;q++) {
	    if (q*(q-1)/2>k) break;
	}
	q--;
	for (int i=0; i<q; i++) {
	    a[i][p+x]=a[p+x][i]=1;
	}
	x++;
	k-=q*(q-1)/2;
    }
    printf("%d\n", p+x);
    for (int i=0; i<p+x; i++) {
	for (int j=0; j<p+x; j++) {
	    printf("%d", int(a[i][j]));
	}
	puts("");
    }
	    
    return 0;
}