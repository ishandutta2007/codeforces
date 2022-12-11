#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int main()
{
	int a1, a2, k1, k2, n;
	cin>>a1>>a2>>k1>>k2>>n;
	int mi = n - a1*(k1-1) - a2*(k2 - 1);
	if(mi < 0) mi = 0;
	if(k1 > k2) swap(a1, a2), swap(k1, k2);
	int mx;
	if(n/k1 <= a1){
        mx = n/k1;
	}
	else{
        mx = a1;
        n = n - a1*k1;
        mx += n/k2;
	}
	cout<<mi<<" "<<mx<<endl;
}