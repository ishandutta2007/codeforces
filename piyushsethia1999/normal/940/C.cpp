#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF (1<<30)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int n,k;
	cin>>n>>k;

	cin>>s;
	std::vector<char> v;
	bool A[26]={false};
	for (int i = 0; i < n; ++i)
	{
		if(!A[s[i]-97]){
			v.pb(s[i]);
		}
	}
	sort(v.begin(),v.end());
	std::map<char, int> m;
	int size=v.size(); 
	for (int i = 0; i < size; ++i)
	{
		m[v[i]] = i;
	}
	if(n<k){
		string str(k-n,v[0]);
		s+=str;
	}
	else{
		s=s.substr(0,k);
		int pos=k;
		while(pos>0){
			pos--;
			if(m[s[pos]]==(size-1)){
				s[pos]=v[0];
			}
			else{
				s[pos]=v[m[s[pos]]+1];
				break;
			}
		}
	}
	cout<<s<<"\n";
}