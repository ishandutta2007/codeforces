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
	int x,y;
	cin>>x>>y;
	int a=y,b=y,c=y;
	int cnt=0;
	int temp;
	while(true)
	{
		if((b+c-1)>=x){
			cnt+=3;
			break;
		}
		else{
			cnt++;
			temp = b+c-1;
			a=b;
			b=c;
			c=temp;
		}
	}
	cout<<cnt;
}