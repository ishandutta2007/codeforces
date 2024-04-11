#include <bits/stdc++.h>
using namespace std;
int mx[200007];
int main()
{
	int n,k;
	string s,sk;
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++) sk+=(s[i%k]);
	bool vc=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]>sk[i])
		{
			vc=false;
			break;
		}
		if(s[i]<sk[i])
		{
			vc=true;
			break;
		}
	}
	if(vc) {cout<<n<<endl<<sk; return 0;}
	for(int j=k-1;j>=0;j--) if(s[j]!='9') {char c=s[j]; for(int i=j;i<n;i+=k) sk[i]=c+1; for(int a=j+1;a<k;a++) for(int i=a;i<n;i+=k) sk[i]='0'; break;}
	cout<<n<<endl<<sk;
}