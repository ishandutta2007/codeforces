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
	int n;
	string str;
	int fact[10];
	fact[0]=1;
	for (int i = 1; i < 11; ++i)
	{
		fact[i] = fact[i-1]*i;
	}
	string ptr = "";
	cin>>n;
	cin>>str;
	int A[10]={0};
	for (int i = 0; i < n; ++i)
	{
		A[(int)str[i]-48]++;
	}
	if(A[9]){
		A[7]+=A[9];
		A[3]+=(2*A[9]);
		A[2]+=A[9];
		A[9]=0;
	}
	if(A[8]){
		A[7]+=A[8];
		A[2]+=(3*A[8]);
		A[8]=0;
	}
	if(A[6]){
		A[5]+=(A[6]);
		A[3]+=A[6];
		A[6]=0;
	}
	if(A[4]){
		A[3]+=(A[4]);
		A[2]+=(2*A[4]);
		A[4]=0;
	}
	for (int i = 9; i > 1; --i)
	{
		for (int j = 0; j < A[i]; ++j)
		{
			cout<<i;
		}
	}
}