#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int n;
int t1, t2;
int main()
{
	cin>>n;
	t1 = 0;//
	t2 = 1;//
	ll ans1 = 0, ans2 = 0;
	int cur = 1;
	for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        if(x < 0) cur = -cur;
        if(cur < 0){
            ans1 += t2;
            ans2 += t1;
        }
        else{
            ans1 += t1;
            ans2 += t2;
        }
        if(cur < 0) t1++; else t2++;
	}
	cout<<ans1<<" "<<ans2<<endl;
}