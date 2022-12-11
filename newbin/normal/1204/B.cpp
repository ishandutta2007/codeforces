#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int main()
{
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	ll mi = n-l+1;
	ll t = 1;
	for(int i = 1; i < l; ++i){
        t<<=1;
        mi += t;
	}
	ll mx = 0;
	t = 1;
	for(int i = 1; i < r; ++i){
        mx += t;
        t<<=1;
	}
	mx += t*(n-r+1);
	cout<<mi<<" "<<mx<<endl;
}