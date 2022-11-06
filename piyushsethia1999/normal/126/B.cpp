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
int KMP(string s) {
	int l = s.size();

	std::vector<int> lps(l);
	
	lps[0] = 0;

	int templps;
	
	bool A[1000000]={0};
	A[0] = true;
	for (int i = 1; i < l; ++i)
	{
		templps = lps[i-1];
		while(templps != 0 && s[i] != s[templps]) 
			templps = lps[templps-1];
		if(s[i] == s[templps]) templps++;
		lps[i] = templps;
		if(i!=(l-1))
			A[templps] = true;
	}
	int k = lps[l-1];
	while(A[k] != true){
		k = lps[k-1];
	}
	return k;
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
	string s;
	cin>>s;
	int l = KMP(s);
	if(l == 0)
		cout<<"Just a legend";
	else{	for (int i = 0; i < l; ++i)
	{
		cout<<s[i];
	}
}
}