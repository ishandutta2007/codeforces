#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+1;
int s[800][800];
int a[maxn];
int main()
{
	int q; cin>>q;
	while(q--){
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1){
            a[x] += y;
            for(int i = 1; i < 800; ++i)
                s[i][x%i] += y;
        }
        else{
            if(x < 800)
                printf("%d\n", s[x][y]);
            else{
                int ans = 0;
                for(int i = y; i < maxn; i += x) ans += a[i];
                printf("%d\n", ans);
            }
        }
	}
}