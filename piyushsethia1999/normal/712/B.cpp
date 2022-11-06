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
	string str;
	cin>>str;
	int l = str.size();
	if(l&1)
	{
		cout<<"-1";
	}
	else{
		int L=0;
		int R=0;
		int U=0;
		int D=0;
		for (int i = 0; i < l; ++i)
		{
			if(str[i] == 'L')
				L++;
			else if(str[i] == 'D')
				D++;
			else if(str[i] == 'U')
				U++;
			else
				R++;
		}
		cout << ((L-R>0?L-R:R-L) + (U-D>0?U-D:D-U))/2;
	}
}