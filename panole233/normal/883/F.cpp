#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

map <string,bool> ma;
map <string,bool> ::iterator pos;

int n,len,ans;
string s,ss;

int main()
{
	scanf("%d\n",&n);
	ma.clear(); ans=0;
	while (n--)
	{
		cin>>s;
		len=s.length();
		while (s[len-1]>'z'||s[len-1]<'a') len--; 
		s=s.substr(0,len);
		for (int i=0; i<len; i++)
		{
			if (s[i]=='h')
			{
				int j=i-1;
				while (j>=0&&s[j]=='k') j--;
				len-=(i-j-1);
				for (int k=j+1; k<=len-1; k++) s[k]=s[k+(i-j-1)];
				i=j+1;
			} 
		}
		s=s.substr(0,len);
		for (int i=0; i<len; i++)
			if (s[i]=='u')
			{
				len++; s=s+s[len-2];
				for (int j=len-2; j>=i+2; j--) s[j]=s[j-1];
				s[i]=s[i+1]='o';
			}
		s=s.substr(0,len);
		pos=ma.find(s);
		if (pos==ma.end()) ma.insert(make_pair(s,1)),ans++;
	}
	printf("%d\n",ans);
	return 0;
}