#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
char s[maxn];
int main()
{
	int n, k;cin>>n>>k;
	scanf("%s", s);
	if(k == 0){
        printf("%s\n", s);return 0;
	}
	if(n == 1){
        printf("0\n"); return 0;
	}
	for(int i = 0; i < n; ++i){
        if(k==0) break;
        if(i == 0 && s[i] > '1') k--, s[i] = '1';
        else if(i > 0 && s[i] > '0') k--, s[i] = '0';
	}
	printf("%s", s);
}