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
	int n,d;
	cin>>n>>d;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int min =100000000;
	for(int i=1;i<=100;i++)
	{
		int size = n-(upper_bound(v.begin(),v.end(),d+i)-lower_bound(v.begin(),v.end(),i));
		if(size<min){
		    min = size;
		}
	}
	cout<<min;
}