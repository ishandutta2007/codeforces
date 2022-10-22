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

int cnt1,cnt2;string s;

signed main()
{
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]=='a')cnt1++;
		else cnt2++;
	if (cnt2>=cnt1)cout<<cnt1*2-1;
	else cout<<cnt1+cnt2;
	return 0;
}