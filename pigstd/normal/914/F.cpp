#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
bitset<M>p[26],ans;
char s1[M],s2[M];
int q;

int main()
{
	cin>>s1+1>>q;
	for (int i=1;i<=strlen(s1+1);i++)
		p[s1[i]-'a'][i]=1;
	for (int i=1;i<=q;i++)
	{
		int opt;cin>>opt;
		if (opt==1)
		{
			int k;
			cin>>k>>s2+1;
			p[s1[k]-'a'][k]=0;
			s1[k]=s2[1];
			p[s1[k]-'a'][k]=1;
		}
		else
		{
			int l,r;
			cin>>l>>r>>s2+1;
			ans.set();
			for (int i=1;i<=strlen(s2+1);i++)
				ans&=p[s2[i]-'a']>>(i-1);
			int ans1=(ans>>l).count();
			int ans2=(ans>>(r-strlen(s2+1)+2)).count();
			cout<<max(0,ans1-ans2)<<endl;
		}
	}
	return 0;
}