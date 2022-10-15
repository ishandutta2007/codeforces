#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
ll n,a,b,i,j,m,c,d,k,t,t1;

void done()
 {
 	cout<<"-1";
 	fclose(stdin);
 	fclose(stdout);
 	exit(0);
 }
int main() {
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>a>>b;
		c=ceil(double(n)/2);
		d=ceil(double(c)/a);
		ll e=(a+b)*(d-1)+(c-a*(d-1));
		cout<<max(e,n)<<endl;
	}
}