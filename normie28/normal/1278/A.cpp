#include <bits/stdc++.h>
using namespace std;

int t,k,n,m,i,j,res=0,cnt[26];
string a,b;
int ck(int x)
{
	int i,cnt2[26];
	for (i=0;i<26;i++) cnt2[i]=0;
	for (i=0;i<n;i++) cnt2[b[x+i]-97]++;
	//	for (i=0;i<26;i++) cout<<cnt2[i]; cout<<endl;
	for (i=0;i<26;i++) if (cnt[i]-cnt2[i]) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (k=1;k<=t;k++)
	{
		res=0;
		cin>>a>>b;
		n=a.length();
		m=b.length();
		for (i=0;i<26;i++) cnt[i]=0;
		for (i=0;i<n;i++) cnt[a[i]-97]++;
	//	cout<<n<<m<<endl;
		for (i=0;i<=m-n;i++) res+=ck(i);
	//	for (i=0;i<26;i++) cout<<cnt[i]; cout<<endl;
		if (res) cout<<"YES"; else cout<<"NO";
		cout<<endl;
	}
}