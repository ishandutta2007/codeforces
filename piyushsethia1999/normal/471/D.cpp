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
void KMP(int A[], int n, int k){
	std::vector<int> lps(n);
	int count = 0;

	lps[0] = 0;
	if(lps[0] == k)
		count++;
	int temp;
	for (int i = 1; i < n; ++i)
	{
		temp = lps[i-1];
		while(temp>0 && A[temp] != A[i]) {
			temp = lps[temp-1];
		}
		if(A[i] == A[temp]) temp++;
		lps[i] = temp;
		if(lps[i] == k)
			count++;
	}
	cout<<count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("/home/piyush/Documents/input.txt", "r", stdin);
	freopen("/home/piyush/Documents/output.txt", "w", stdout);
	#endif/**/
	int n, k, x1, x2;
	cin>>n>>k;
	cin>>x1;
	int A[n-1+k];
	for (int i = k; i < (n-1+k); ++i)
	{
		cin >> x2;
		A[i] = x1 - x2;
		x1 = x2;
	}
	A[k-1] = 2000000001;
	cin >> x1;
	for (int i = 0; i < (k-1); ++i)
	{
		cin >> x2;
		A[i] = x1 - x2;
		x1 = x2;
	}
	KMP(A, n-1+k, k-1);
}