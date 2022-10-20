#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,A,B,T=0;
string s1,s2;
void init() {
	string s(n,'F');
	cout<<s<<endl;
	cin>>A;
	s1=s;
	for (int i=1;i<n;i+=2) {
		s[i]='T';
	}
	cout<<s<<endl;
	cin>>B;
	s2=s;
}
int ask3(int x) {
	string s(s1);
	s[x]=s[x+1]=s[x+2]='T';
	cout<<s<<endl;
	int ret;
	cin>>ret;
	return ret-A;
}
int ask2(int x) {
	string s(s2);
	if (x&1) {
		s[x]='F',s[x+1]='T';
	} else {
		s[x]='T',s[x+1]='F';
	}
	cout<<s<<endl;
	int ret;
	cin>>ret;
	return ret-B;
}
int ask(int x) {
	string s(s1);
	s[x]='T';
	cout<<s<<endl;
	int ret;
	cin>>ret;
	return ret-A;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	init();
	string ans(n,'F');
	for (int i=0;i+2<n;i+=3) {
		int tmp=ask3(i);
		if (tmp==3) {
			ans[i]=ans[i+1]=ans[i+2]='T';
		} else {
			if (tmp==-3) {
				continue;
			}
			int t=ask2(i);
			if (t) {
				if (t>0) {
					ans[i]=s2[i]=='T'?'F':'T';
					ans[i+1]=s2[i+1]=='T'?'F':'T';
				} else {
					ans[i]=s2[i];
					ans[i+1]=s2[i+1];
				}
			} else {
				if (tmp>0) {
					ans[i]=ans[i+1]='T';
				} else {
					ans[i]=ans[i+1]='F';
				}
			}
			int tot=(tmp+3)/2;
			tot-=ans[i]=='T';
			tot-=ans[i+1]=='T';
			ans[i+2]=tot?'T':'F';
		}
	}
	while (--n%3!=2&&n>=0) {
		if (ask(n)>0) {
			ans[n]='T';
		}
	}
	cout<<ans<<endl;
	
	return 0;
}