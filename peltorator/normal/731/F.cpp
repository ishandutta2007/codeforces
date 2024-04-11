#include <bits/stdc++.h>

using namespace std;
const double pi=acos(-1.0);
const double eps=1e-9;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define re return
#define vi vector <int> 
#define pii pair <int,int>
#define pll pair <long long , long long>
typedef long long ll;

const int N=(int)2e5+5;
ll n,a[N],ans;

int bs(int l,int r,int val)
{
	if(l==r) return l;
	if(r==l+1)
		if(a[l]>=val)return l; else return r;
	int m=(r+l)/2;
	if(a[m]>=val) return bs(l,m,val);else return bs(m,r,val);
}
int main()
{
	ios:: sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		ll curans=0;
		if(i!=0&&a[i]==a[i-1])continue;
		for(int val=a[i];val<=300000;val+=a[i])
		{
			if(a[n-1]<val)break;
			curans+=(n-bs(0,n-1,val))*a[i];
		}
		ans=max(ans,curans);
	}
	cout << ans;
	return 0;
}