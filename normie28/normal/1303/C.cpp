#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
int n,a,b,i,j,m,c,d,k,t,t1,used[26];
vector<int> keys;
 void done()
 {
 	cout<<"NO"<<endl;
 }
int main() {
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
	    string s;
		cin>>s;
		n=s.length();
		for (i=0;i<26;i++) used[i]=0;
		keys.clear();
		keys.push_back(s[0]-97);
		used[s[0]-97]=1;
			int fail=0;
		for (i=1;i<n;i++)
		{
			a=s[i-1]-97;
			b=s[i]-97;
			if (!used[b])
			{
				if (keys[0]==a)
				{
					keys.insert(keys.begin(),b);
				}
				else if (keys[keys.size()-1]==a)
				{
					keys.insert(keys.end(),b);
				}
				else
				{
					cout<<"NO\n"; fail=1; break;
				}
			}
			else
			{
				int posa,posb;
				for (j=0;j<keys.size();j++)
				{
					if (keys[j]==a) posa=j;
					if (keys[j]==b) posb=j;
				}
				if (abs(posa-posb)==1); else {cout<<"NO\n"; fail=1; break;}
			}
			used[b]=1;
		}
		if (fail) continue;
		cout<<"YES\n";
		for (int k: keys)
		{
			char c=k+97;
			cout<<c;
		}
		for (i=0;i<26;i++) if (!used[i]) {
			
			char c=i+97;
			cout<<c;
		}
		cout<<endl;
	}
}