#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define pb push_back

int ans[1010];

int main()
{
	fill(ans, ans+1001, 2e9);
	setbuf(stdout, 0);
    int n;
    read(n);
    for(int i=9; 0<=i; --i){
		{
			vector<int> q;
			for(int j=1; j<=n; ++j) if(1&(j>>i)) q.pb(j);
			if(q.size() && int(q.size()) < n){
				printf("%d\n", int(q.size()));
				for(int x:q) printf("%d ", x); putchar(10);
				fflush(stdout);
				for(int j=1; j<=n; ++j){
					int x; read(x);
					if(1&(j>>i)){
						
					} else {
						ans[j]=min(ans[j], x);
					}
				}
			}
		}
		{
			vector<int> q;
			for(int j=1; j<=n; ++j) if(1&(j>>i)) 1; else q.pb(j);
			if(q.size() && int(q.size()) < n){
				printf("%d\n", int(q.size()));
				for(int x:q) printf("%d ", x); putchar(10);
				fflush(stdout);
				for(int j=1; j<=n; ++j){
					int x; read(x);
					if(1&(j>>i)){
						ans[j]=min(ans[j], x);
					}
				}
			}
		}
    }
    printf("-1\n");
    for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
    fflush(stdout);
    return 0;
}