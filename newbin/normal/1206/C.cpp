#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn*2];
int main()
{
	int n;cin>>n;
	if(n%2 == 0){
        printf("NO\n"); return 0;
	}
	int pos = 1;
	for(int i = 1; i <= n; ++i){
        if(i&1) a[i] = pos, a[i+n] = pos+1;
        else a[i] = pos+1, a[i+n] = pos;
        pos += 2;
	}
	printf("YES\n");
	for(int i = 1; i <= 2*n; ++i){
        if(i > 1) printf(" ");
        printf("%d", a[i]);
	}printf("\n");
}