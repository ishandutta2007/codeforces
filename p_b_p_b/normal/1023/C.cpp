#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(long long& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
}read;
#define sz 201010
char ch[sz];
char ans[sz];
int fr[sz];
bool cut[sz];
stack<int>st;
int main()
{
	int n,K,i,j,k,x,y,z,l;
	read>>n>>K;
	cin>>ch;l=n;
	for (i=0;i<l;i++)
	{
		if (ch[i]=='(') st.push(i);
		else fr[i]=st.top(),st.pop();
	}
	for (i=l-1;n!=K;i--) 
		if (!cut[i]&&ch[i]==')') 
			cut[i]=cut[fr[i]]=1,n-=2;
	for (i=0;i<l;i++) if (!cut[i]) putchar(ch[i]);
}