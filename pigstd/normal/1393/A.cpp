#include<bits/stdc++.h>
using namespace std;

int T;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	T=read();
	while(T--)
		cout<<read()/2+1<<endl;
	return 0;
}