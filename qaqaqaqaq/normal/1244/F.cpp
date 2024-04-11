#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,k;
char s[maxn],ans[maxn];
bool bk[maxn];

void inv(int u){
	if (s[u]=='B'){
		s[u]='W';
	}
	else{
		s[u]='B';
	}
}

int main(){
	cin>>n>>k;
	cin>>s;
	int j=-1;
	for (int i=0;i<n;++i){
		if (s[i]==s[(i+1)%n]){
			bk[i]=1;
			j=i;
		}
	}
	for (int i=1;i<=n;++i){
		if (s[i%n]==s[i-1]){
			bk[i%n]=1;
			j=i%n;
		}
	}
	if (j==-1&&k%2){
		for (int i=0;i<n;++i){
			inv(i);
		}
		cout<<s<<endl;
		return 0;
	}
	int i=0;
	while (i<n){
		while (i<n&&bk[(i+j)%n]){
			i++;
		}
		int l=i;
		while (i<n&&!bk[(i+j)%n]){
			i++;
		}
		if (i>=n) break;
		if (i-l>=2*k){
			for (int r=0;r<k;++r){
				s[(l+r+j)%n]=s[(l-1+j)%n];
				s[(i+j-1-r)%n]=s[(i+j)%n];
			}
			for (int r=l+k;r<i-k;++r){
				if (k%2){
					inv((r+j)%n);
				}
			}
		}
		else{
		//	cout<<i<<" "<<j<<" "<<l<<endl;
			for (int r=0;r<(i-l+1)/2;++r){
				s[(l+r+j)%n]=s[(l-1+j)%n];
				s[(i+j-1-r)%n]=s[(i+j)%n];
			}
		}
	}
	cout<<s<<endl;
	return 0;
}