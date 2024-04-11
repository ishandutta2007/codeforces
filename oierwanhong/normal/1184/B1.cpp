#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100010;
int a[maxn],sum[maxn],pp[maxn];
struct node
{
    int d,g;
    bool operator < (const node &q) const
    {
        return d < q.d;
    }
};
node x[maxn];
signed main()
{
    //freopen("in","r",stdin);
    int s,b;
    cin >> s >> b;
    for(int i = 1;i <= s; i++)
        cin >> a[i];
    for(int i = 1;i <= b; i++)
    {
        cin >> x[i].d >> x[i].g;
        pp[i] = x[i].d;
    }
    sort(x+1,x + b+1);
    sum[0]=0;
    for(int i=1;i<=b;i++)
        sum[i] = sum[i - 1] + x[i].g;
    for(int i=1;i<=s;i++)
    {
        unsigned l=0,r=b,mid;
        while(l<r)
		{
			mid=(l+r+1)>>1;
        	if(x[mid].d<=a[i])l=mid;
        	else r=mid-1;
		}
        cout<<sum[r]<<" ";
    }
    cout << endl;
    return 0;
}