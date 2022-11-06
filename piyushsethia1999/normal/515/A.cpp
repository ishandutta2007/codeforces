#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,s;
	cin>>a>>b>>s;
	a = a>0?a:-a;
	b = b>0?b:-b;

	if((s-a-b)%2 == 0 && (s-a-b)>=0)
	{
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}