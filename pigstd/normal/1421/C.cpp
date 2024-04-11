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

signed main()
{
	string s;cin>>s;
	int len=s.size();
	cout<<3<<endl;
	cout<<"L 2"<<endl;
	len++;
	cout<<"R 2"<<endl;
	len=len*2-2;
	cout<<"R "<<len-1<<endl;
	return 0;
}