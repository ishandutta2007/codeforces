#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn=1e6+10;
int cp[maxn], mp[maxn];
int n,k;
 
main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=2; i<maxn; i++)
	if(!mp[i])
	    for(int j=i; j<maxn; j+=i)
		mp[j]=i;
    for(int i=0; i<n; i++)
    {
	int x;
	cin>>x;
	while(x>1)
	{
	    int k=0;
	    int p=mp[x];
	    while(x%p==0)x/=p, k++;
	    cp[p]=max(k,cp[p]);
	}
    }
    while(k>1)
    {
	if((--cp[mp[k]]) < 0)
	    return cout<<"No", 0;
	k/=mp[k];
    }
    cout<<"Yes";
    return 0;
}