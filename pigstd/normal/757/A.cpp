#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

string s;
int ans=1e18;
//Bulbasaur

int find(char ch)
{
	int sum=0;
	for (int i=0;i<s.size();i++)
		sum+=(ch==s[i]);
	return sum;
}

signed main()
{
	cin>>s;
	ans=min(ans,find('B'));
	ans=min(ans,find('u')/2);
	ans=min(ans,find('l'));
	ans=min(ans,find('b'));
	ans=min(ans,find('a')/2);
	ans=min(ans,find('s'));
	ans=min(ans,find('r'));
	cout<<ans<<endl;
	return 0;
}