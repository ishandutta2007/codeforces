#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a[200001],m[200001]={0};
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		
		if(a[i]>i){
			if(pos<(a[i]-i)){
				pos=a[i]-i;
			}
		}
		if(pos){
			pos--;
			m[i]=1;
		}
	}
	pos=0;
	for(int i=n;i>=1;i--)
	{
		if(pos){
			pos--;
			m[i]=1;
		}
		if(i>a[i]){
			if(pos<(i-a[i])){
				pos=i-a[i];
			}
		}
	}
	cin>>s;
	bool b=true;
	for(int i=1;i<=n;i++)
	{
		if(m[i]==1){
			if(s[i-1]!='1'){
				b=false;
				break;
			}
		}
	}
	if(b){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}