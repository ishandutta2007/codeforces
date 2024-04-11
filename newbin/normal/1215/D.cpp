#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int n;
const int maxn = 2e5 + 50;
char s[maxn];
int x, y;
int sx, sy;
int main()
{
	cin>>n;
	scanf("%s", s+1);
	x = y = 0;
	sx = sy = 0;
	for(int i = 1; i <= n/2; ++i){
        if(s[i] == '?') x++;
        else sx += s[i] - '0';
	}
	for(int i = n/2 + 1; i <= n; ++i){
        if(s[i] == '?') y++;
        else sy += s[i] - '0';
	}
	if(x == y){
        if(sx == sy) printf("Bicarp\n");
        else printf("Monocarp\n");
	}
	else{
        if(x < y) swap(x, y), swap(sx, sy);
        if(sx >= sy){
            printf("Monocarp\n");
        }
        else{
            int d = sy - sx;
            int t = 9*(x-y)/2;
            if(t == d) printf("Bicarp\n");
            else printf("Monocarp\n");
        }
	}
}