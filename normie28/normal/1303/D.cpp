#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
ll n,a,b,i,j,m,c,d,k,t,t1,used[63],need[63];
vector<int> pool,bag;
 void done()
 {
 	cout<<"NO"<<endl;
 //	break;
 }
int main() {
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		pool.clear();
		bag.clear();
		cin>>n>>m;
		for (i=0;i<=60;i++)
		{
			need[i]=n%2;
			n/=2;
			used[i]=0;
		}
		for (i=0;i<m;i++)
		{
			cin>>a;
			used[ll(log2(a))]++;
		}
		ll store=0,cnt=0,fail=0;
		for (i=0;i<=60;i++)
		{
			store+=used[i]*((1ll)<<i);
			if (store>=need[i]*((1ll)<<i)) 
			{
				store-=need[i]*((1ll)<<i);
			}
			else
			{
				int done=0;
				for (j=i+1;j<=60;j++)
				if (used[j])
				{
					cnt+=j-i;
					used[j]--;
					for (int k=i+1;k<j;k++) used[k]++;
					store+=((1ll)<<i);
					done=1;
					break;
				}
				if (!done) {
					cout<<"-1\n";
					fail=1;
					break;
				}
				
			}
		}
		if (!fail) cout<<cnt<<endl;
	}
}