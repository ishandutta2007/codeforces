#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
multiset<char> st;
int main()
{
	int n;
	scanf("%d",&n);
	char s[20];
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='2')
		{
			st.insert(2);
		}
		if(s[i]=='3')
		{
			st.insert(3);
		}
		if(s[i]=='4')
		{
			st.insert(2);
			st.insert(2);
			st.insert(3);
		}
		if(s[i]=='5')
		{
			st.insert(5);
		}
		if(s[i]=='6')
		{
			st.insert(5);
			st.insert(3);
		}
		if(s[i]=='7')
		{
			st.insert(7);
		}
		if(s[i]=='8')
		{
			st.insert(7);
			st.insert(2);
			st.insert(2);
			st.insert(2);
		}
		if(s[i]=='9')
		{
			st.insert(7);
			st.insert(3);
			st.insert(3);
			st.insert(2);
		}
	}
	vector<char> ans;
	for(multiset<char>::iterator it=st.begin();it!=st.end();it++)
		ans.pb(*it+'0');
	for(int i=ans.size()-1;i>=0;i--)
		putchar(ans[i]);
	return 0;
}