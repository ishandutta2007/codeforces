#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
int n,a,b,i,j,m,c,d,k;

void done()
 {
 	cout<<"-1";
 	fclose(stdin);
 	fclose(stdout);
 	exit(0);
 }
int main() {
	fio;
	cin>>n;
	for (j=0;j<n;j++)
	{
	string s;
	a=-1; b=1000; c=0;
	cin>>s;
	m=s.length();
	for (i=0;i<m;i++)
	{
		if (s[i]-48)
		{
			c++;
			if (i>a) a=i;
			if (i<b) b=i;
		}
	}
	
		cout<<max(a-b+1-c,0)<<endl;
	}
}