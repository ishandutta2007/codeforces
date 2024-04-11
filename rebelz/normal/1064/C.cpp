#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,k,now;
int cnt[105],s[100005],a[105],ans[105];

int main(){
	cin>>n;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'a';
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
		cnt[s[i]]++;
	for(int i=0;i<=25;i++){
		for(int j=1;j<=cnt[i];j++){
			cout<<(char)(i+'a');
		}
	}
	cout<<endl;
	return 0;
}