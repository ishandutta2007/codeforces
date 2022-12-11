#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int n, m;
const int maxn = 550;
int a[maxn], b[maxn];
int main()
{
	cin>>n;
	for(int i = 0; i<n; ++i){
        int x;scanf("%d", &x); a[x] = 1;
	}
	cin>>m;
	for(int i = 0; i < m; ++i){
        int x;scanf("%d", &x); b[x] = 1;
	}
	for(int i = 1; i <= 200; ++i){
        for(int j = 1; j <= 200; ++j){
            if(a[i] && b[j]){
                if(i+j > 200){
                    printf("%d %d\n", i, j); return 0;
                }
                else if(!a[i+j] && ! b[i+j]){
                    printf("%d %d\n", i, j); return 0;
                }
            }
        }
	}
}